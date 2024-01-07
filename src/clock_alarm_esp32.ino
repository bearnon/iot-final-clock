#include <vector>
#include <Audio.h>
#include "FS.h"
#include "SD_MMC.h"
#define LV_CONF_INCLUDE_SIMPLE
#include <lv_conf.h>
#include <lvgl.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <uRTCLib.h>
#include <WiFi.h>
#include <time.h>


#define TFT_GREY 0x5AEB

LV_FONT_DECLARE(credc_48);
LV_FONT_DECLARE(credc_24);

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

//default SD card Pins
#define SD_MMC_CMD 38
#define SD_MMC_CLK 39
#define SD_MMC_D0  40

//I2C Amplifier
//BCLK
#define I2S_BCLK   48
//DIN
#define I2S_DOUT   45
//LRC
#define I2S_LRC    47

#define MAX98357_GAIN 41
#define MAX98357_SD_MODE 42

typedef struct _noti_item_t {
  int id;
  lv_calendar_date_t date;
  int hour;
  int min;
  char description[128];
  lv_obj_t *list_btn;
} noti_item_t;

// const char *ssid = "HSCC";
const char *ssid = "CHT Wi-Fi Home-CJ7";
// const char *password = "hscc54747";
const char *password = "qwertyuiop";
const char *ntpServer = "time.stdtime.gov.tw";
const long gmtOffset_sec = 8*60*60;
const int daylightOffset_sec = 0;

uRTCLib rtc(0x68);
Audio audio;
std::vector<noti_item_t> noti_list_vec;
int num_ids = 0;
TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

void sd_setup(){
  SD_MMC.setPins(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0);
  if (!SD_MMC.begin("/sdcard", true, true, SDMMC_FREQ_DEFAULT, 5)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD_MMC card attached");
    return;
  }
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);
}

void audio_setup(){
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  //Set volume
  audio.setVolume(8);  // 0...21
  //Select SD card and music file
  // audio.connecttoFS(SD_MMC, "StarWars60.wav");
}

void audio_eof_mp3(const char *info){  //end of file
    Serial.print("audio_info: "); Serial.println(info);
    audio.connecttoFS(SD_MMC, "StarWars60.wav");
    // static int i=0;
    // if(i==0) audio.connecttoSD("/wave_test/If_I_Had_a_Chicken.mp3");
    // if(i==1) audio.connecttoSD("/wave_test/test_8bit_stereo.wav");
    // if(i==2) audio.connecttoSD("/wave_test/test_16bit_mono.wav");
    // i++;
    // if(i==3) i=0;
}

void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // Calibrate
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.println("Touch corners as indicated");

  tft.setTextFont(1);
  tft.println();

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  Serial.println(); Serial.println();
  Serial.println("// Use this calibration code in setup():");
  Serial.print("  uint16_t calData[5] = ");
  Serial.print("{ ");

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }

  Serial.println(" };");
  Serial.print("  tft.setTouch(calData);");
  Serial.println(); Serial.println();

  tft.fillScreen(TFT_BLACK);
  
  // tft.setTextColor(TFT_GREEN, TFT_BLACK);
  // tft.println("Calibration complete!");
  // tft.println("Calibration code sent to Serial port.");
  tft.setTouch(calData);
  delay(4000);
}

uint32_t targetTime = 0;                    // for next 1 second timeout

static uint8_t conv2d(const char* p); // Forward declaration needed for IDE 1.6.x

uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6); // Get H, M, S from compile time
bool tick = false;
int y,m,d;
bool getNTPServerTime = true;
int wifi_ckpt = 0;
int wifi_on = 1;
byte omm = 99, oss = 99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

void initDateTime() {
  rtc.refresh();
  hh = rtc.hour();
  mm = rtc.minute();
  ss = rtc.second();
  y = rtc.year() + 2000;
  m = rtc.month();
  d = rtc.day();
  Serial.printf("%d %d %d %d %d %d\n", hh, mm, ss, y, m, d);
}

void setLocalTime() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  hh = timeinfo.tm_hour;
  mm = timeinfo.tm_min;
  ss = timeinfo.tm_sec;
  y = timeinfo.tm_year + 1900;
  m = timeinfo.tm_mon + 1;
  d = timeinfo.tm_mday;
  int dayofweek = timeinfo.tm_wday;
  Serial.printf("%d %d %d %d %d %d\n", hh, mm, ss, y, m, d); 
  rtc.set(ss, mm, hh, dayofweek, d, m, y % 100);
}

bool fetchTimeFromNTPServer(){
  if(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    wifi_ckpt += 1;
    if(wifi_ckpt > 50){
      Serial.println("No wifi detected");
      wifi_on = 0;
    }
    return false;
  }
  Serial.println("CONNECTED");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  setLocalTime();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  wifi_on = 0;
  return true;
}

int dayNumber(int day, int month, int year) {
 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}

int monthdays(int month, int year) {
  static int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if(month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    return 29;
  return d[month-1];
}

char *month_abbr[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char week_capital[] = "UMTWRFS";
char *week_abbr[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

void readTouch(){
  uint16_t tx, ty;
  bool touched = tft.getTouch(&tx, &ty, 600);
  if(touched){
    Serial.println(tx);
    Serial.println(ty);
  }
}

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp_drv );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_drv, lv_indev_data_t * data )
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch( &touchX, &touchY, 300 );

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        // Serial.print( "Data x " );
        // Serial.println( touchX );

        // Serial.print( "Data y " );
        // Serial.println( touchY );
    }
}

void date_parse(char const *date, int *yr, int *mo, int *d) { 
    // int month, day, year;
    char buff[4];
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    sscanf(date, "%s %d %d", buff, d, yr);
    *mo = (strstr(month_names, buff)-month_names)/3+1;
    // sprintf(buff, "%d%02d%02d.txt", year, month, day);
}

/* lvgl variables initialize */
static const lv_font_t *font_large, *font_normal, *font_clock, *font_clock_small;
static lv_obj_t *tv, *calendar, *text_clock, *dmy, *latest_noti, *temperature, *panel, *noti_list, *modify_panel, *kb, *roller_hour, *roller_min, *description;
static lv_style_t style_clock, style_clock_small;
lv_calendar_date_t pressed_date;
noti_item_t *selected_noti;

void panel_close_btn_event_cb(lv_event_t *);

inline lv_obj_t* close_btn_create(lv_obj_t *parent, lv_event_cb_t event_cb) {
  Serial.println("close_btn_create");
  lv_obj_t * close_btn = lv_btn_create(parent);
  lv_obj_set_size(close_btn, 20, 20);
  lv_obj_add_flag(close_btn, LV_OBJ_FLAG_FLOATING);
  lv_obj_align(close_btn, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_obj_add_event_cb(close_btn, event_cb, LV_EVENT_ALL, parent);
  lv_obj_set_style_radius(close_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_bg_color(close_btn, lv_palette_main(LV_PALETTE_RED), 0);
  lv_obj_set_style_bg_img_src(close_btn, LV_SYMBOL_CLOSE, 0);
  lv_obj_set_style_text_font(close_btn, lv_theme_get_font_large(close_btn), 0);
  return close_btn;
}

bool compareDateTime(lv_calendar_date_t *d1, int hour1, int min1, lv_calendar_date_t *d2, int hour2, int min2){
  // if(d1->year > d2->year) return true;
  // if(d1->year < d2->year) return false;
  if(d1->year != d2->year) return d1->year > d2->year;
  if(d1->month != d2->month) return d1->month > d2->month;
  if(d1->day != d2->day) return d1->day > d2->day;
  if(hour1 != hour2) return hour1 > hour2;
  return min1 > min2;
}

void diffDateTime(int *result_day, int *result_hour, int *result_min, lv_calendar_date_t *d1, int hour1, int min1, lv_calendar_date_t *d2, int hour2, int min2){
  struct tm t1, t2;
  t1.tm_year = d1->year;
  t1.tm_mon = d1->month;
  t1.tm_mday = d1->day;
  t1.tm_hour = hour1;
  t1.tm_min = min1;
  t1.tm_sec = 0;
  t1.tm_isdst = -1;
  t2.tm_year = d2->year;
  t2.tm_mon = d2->month;
  t2.tm_mday = d2->day;
  t2.tm_hour = hour2;
  t2.tm_min = min2;
  t2.tm_sec = 0;
  t2.tm_isdst = -1;
  time_t diff = (mktime(&t1) - mktime(&t2)) / 60;
  *result_min = diff % 60;
  diff /= 60;
  *result_hour = diff % 24;
  *result_day = diff / 24;
  Serial.printf("%d %d %d %d %d %d %d %d %d %d\n", d1->year, d1->month, d1->day, hour1, min1, d2->year, d2->month, d2->day, hour2, min2);
  // result_d->year = diff 
}

bool sameDay(lv_calendar_date_t *d1, lv_calendar_date_t *d2){
  return d1->day == d2->day && d1->month == d2->month && d1->year == d2->year;
}

bool sameTimeMin(int hour1, int min1, int hour2, int min2){
  return min1 == min2 && hour1 == hour2;
}

void updateLatestNoti(){
  if(noti_list_vec.size() == 0){
    return;
  }
  lv_calendar_date_t today;
  today.year = y;
  today.month = m;
  today.day = d;
  noti_item_t *latest = &noti_list_vec[0];
  for(int i = 1; i < noti_list_vec.size(); i++){
    if(compareDateTime(&latest->date, latest->hour, latest->min, &noti_list_vec[i].date, noti_list_vec[i].hour, noti_list_vec[i].min) &&
        compareDateTime(&noti_list_vec[i].date, noti_list_vec[i].hour, noti_list_vec[i].min, &today, hh, mm)
      ){
      latest = &noti_list_vec[i];
    }
  }
  if(!compareDateTime(&latest->date, latest->hour, latest->min, &today, hh, mm))
    return;
  int diff_day, diff_hour, diff_min;
  diffDateTime(&diff_day, &diff_hour, &diff_min, &latest->date, latest->hour, latest->min, &today, hh, mm);
  lv_label_set_text_fmt(latest_noti, "Next: %s - in %d day %d hour %d minute", latest->description, diff_day, diff_hour, diff_min);
}

void mbox_close_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  if(code == LV_EVENT_CLICKED){
    audio.stopSong();
    // audio.pauseResume();
    panel_close_btn_event_cb(e);
  }
}

/* update the clock time */
void clock_timer_callback(lv_timer_t *timer){
  if(tick){
    tick = false;
    lv_label_set_text_fmt(text_clock, "%02d:%02d:%02d", hh, mm, ss);
    if(wifi_on){
      if(fetchTimeFromNTPServer())
        lv_label_set_text_fmt(dmy, "%s %d %d", month_abbr[m-1], d, y);
    }
    if(ss % 10 == 0){
      rtc.refresh();
      int temp = rtc.temp();
      lv_label_set_text_fmt(temperature, "%d°C", temp/100 + (temp%100 > 50));
    }
    if(ss == 0){
      
      lv_calendar_date_t today;
      today.year = y;
      today.month = m;
      today.day = d;
      for(int i = 0; i < noti_list_vec.size(); i++){
        if(sameTimeMin(hh, mm, noti_list_vec[i].hour, noti_list_vec[i].min) && sameDay(&today, &noti_list_vec[i].date)){
          Serial.println("ALARM========================");
          const char *btns[] = {"Close"};
          // lv_obj_t *mbox = lv_msgbox_create(lv_layer_top(), "ALARM", noti_list_vec[i].description, btns, false);
          // lv_obj_t *mbox = lv_msgbox_create(lv_layer_top(), "ALARM", "abccc", btns, true);
          lv_obj_t *mbox = lv_obj_create(lv_layer_top());
          lv_obj_center(mbox);
          close_btn_create(mbox, mbox_close_cb);
          // lv_obj_add_event_cb(mbox, mbox_close_cb, LV_EVENT_VALUE_CHANGED, mbox);
          lv_obj_set_flex_flow(mbox, LV_FLEX_FLOW_COLUMN);
          lv_obj_set_flex_align(mbox, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
          lv_obj_t *label1 = lv_label_create(mbox);
          lv_label_set_text(label1, "ALARM!!!");
          lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
          lv_obj_t *label2 = lv_label_create(mbox);
          lv_label_set_text_fmt(label2, "%02d:%02d", hh, mm);
          lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
          lv_obj_t *label3 = lv_label_create(mbox);
          lv_label_set_text(label3, noti_list_vec[i].description);
          lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
          // lv_obj_t *btn = lv_button_create

          audio.connecttoFS(SD_MMC, "StarWars60.wav");
          break;
        }
      }
    }
  }
}

void panel_close_btn_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  if(code == LV_EVENT_CLICKED){

    lv_obj_t * tg = (lv_obj_t*)lv_event_get_user_data(e);
    lv_obj_del(tg);
  }
}

void noti_del_btn_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  if(code == LV_EVENT_CLICKED){

    noti_item_t * tg = (noti_item_t*)lv_event_get_user_data(e);
    // lv_obj_clean(tg->list_btn);
    // lv_obj_del(tg->list_btn);
    lv_obj_add_flag(tg->list_btn, LV_OBJ_FLAG_HIDDEN);
    for(auto it = noti_list_vec.begin(); it != noti_list_vec.end(); it++){
      if(it->id == tg->id){
        noti_list_vec.erase(it);
        break;
      }
    }
    Serial.printf("noti_list_vec size: %d\n", noti_list_vec.size());
    updateLatestNoti();
    // panel_close_btn_event_cb(e);
  }
}

void modify_save_close_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  if(code == LV_EVENT_CLICKED){
    char buf[1024];
    lv_roller_get_selected_str(roller_hour, buf, 3);
    selected_noti->hour = atoi(buf);
    lv_roller_get_selected_str(roller_min, buf, 3);
    selected_noti->min = atoi(buf);
    // selected_noti->description = lv_textarea_get_text(description);
    strcpy(selected_noti->description, lv_textarea_get_text(description));
    lv_snprintf(buf, sizeof(buf), "%02d:%02d - %s", selected_noti->hour, selected_noti->min, selected_noti->description);
    // lv_label_set_text(selected_noti->list_btn, buf);
    for(int i = 0; i < lv_obj_get_child_cnt(selected_noti->list_btn); i++) {
      lv_obj_t * child = lv_obj_get_child(selected_noti->list_btn, i);
      if(lv_obj_check_type(child, &lv_label_class)) {
        lv_label_set_text(child, buf);
        break;
      }
    }
  }
  panel_close_btn_event_cb(e);
  updateLatestNoti();
}


void roller_opts_arange(char *opts, int n){
  char buf[4];
  for(int i = 0; i < n; i++) {
    sprintf(buf, "%02d", i);
    strcat(opts, buf);
    opts[3*i+2] = '\n';
    // Serial.println(buf);
  }
  opts[3*n-1] = '\0';
}

void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * tg = (lv_obj_t *)lv_event_get_user_data(e);
    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_get_act()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_set_style_max_height(kb, LV_HOR_RES * 2 / 3, 0);
            lv_obj_update_layout(tg);   /*Be sure the sizes are recalculated*/
            lv_obj_set_height(tg, LV_VER_RES - lv_obj_get_height(kb) - lv_obj_get_x(tg));
            lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_move_foreground(kb);
            lv_obj_scroll_to_view_recursive(ta, LV_ANIM_OFF);
        }
    }
    else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_set_height(tg, LV_VER_RES - 2 * lv_obj_get_x(tg));
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_indev_reset(NULL, ta);

    }
    else if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_set_height(tg, LV_VER_RES - 2 * lv_obj_get_x(tg));
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);   /*To forget the last clicked object to make it focusable again*/
    }
}

/* click the alarm/notification list button, open modify panel */
void noti_list_btn_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);
  if(code == LV_EVENT_CLICKED){ // create modify panel
    Serial.printf("Clicked %s\n", lv_list_get_btn_text(noti_list, obj));
    noti_item_t *tg = (noti_item_t*)lv_event_get_user_data(e);
    selected_noti = tg;
    lv_calendar_date_t *d = &pressed_date;
    modify_panel = lv_obj_create(lv_layer_top());
    lv_obj_set_size(modify_panel, 280, 200);
    lv_obj_set_pos(modify_panel, 20, 20);
    // lv_obj_center(modify_panel);
    // lv_obj_set_flex_flow(modify_panel, LV_FLEX_FLOW_COLUMN);
    // lv_obj_set_flex_align(modify_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    close_btn_create(modify_panel, modify_save_close_event_cb);
    static lv_coord_t col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(modify_panel, col_dsc, row_dsc);

    lv_obj_t *title = lv_label_create(modify_panel);
    lv_obj_set_grid_cell(title, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 0, 1);
    lv_label_set_text_fmt(title, "Modify notification - %s %d %d", month_abbr[d->month-1], d->day, d->year);
    

    char opts_hour[3*24] = {0}, opts_min[3*60] = {0};
    roller_opts_arange(opts_hour, 24);
    // Serial.printf(opts_hour);
    roller_opts_arange(opts_min, 60);

    lv_obj_t *label1 = lv_label_create(modify_panel);
    lv_obj_set_grid_cell(label1, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_label_set_text(label1, "Time");

    lv_obj_t *rollers = lv_obj_create(modify_panel);
    lv_obj_set_grid_cell(rollers, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_size(rollers, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(rollers, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(rollers, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_top(rollers, 0, 0);
    lv_obj_set_style_pad_left(rollers, 0, 0);
    lv_obj_set_style_pad_bottom(rollers, 0, 0);
    lv_obj_set_style_pad_right(rollers, 0, 0);
    lv_obj_set_style_border_width(rollers, 0, 0);

    roller_hour = lv_roller_create(rollers);
    lv_roller_set_options(roller_hour, opts_hour, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_hour, 2);
    lv_obj_set_style_text_align(roller_hour, LV_TEXT_ALIGN_RIGHT, 0);
    lv_obj_align(roller_hour, LV_ALIGN_RIGHT_MID, -10, 0);
    // lv_obj_add_event_cb(roller_hour, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_hour, tg->hour, LV_ANIM_OFF);

    lv_obj_t *roller_label = lv_label_create(rollers);
    lv_label_set_text(roller_label, ":");

    roller_min = lv_roller_create(rollers);
    lv_roller_set_options(roller_min, opts_min, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_min, 2);
    lv_obj_set_style_text_align(roller_min, LV_TEXT_ALIGN_RIGHT, 0);
    lv_obj_align(roller_min, LV_ALIGN_RIGHT_MID, -10, 0);
    // lv_obj_add_event_cb(roller_hour, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_min, tg->min, LV_ANIM_OFF);

    lv_obj_t *label2 = lv_label_create(modify_panel);
    lv_obj_set_grid_cell(label2, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_label_set_text(label2, "Description");

    description = lv_textarea_create(modify_panel);
    lv_obj_set_grid_cell(description, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    lv_obj_set_size(description, lv_pct(50), 60);
    Serial.println(tg->description);
    lv_textarea_add_text(description, tg->description);
    lv_obj_add_event_cb(description, ta_event_cb, LV_EVENT_ALL, modify_panel);

    lv_obj_t * del_btn = lv_btn_create(modify_panel);
    lv_obj_set_grid_cell(del_btn, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 3, 1);
    lv_obj_set_size(del_btn, 80, 40);
    // lv_obj_add_flag(close_btn, LV_OBJ_FLAG_FLOATING);
    // lv_obj_align(close_btn, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_add_event_cb(del_btn, noti_del_btn_event_cb, LV_EVENT_ALL, tg);
    lv_obj_add_event_cb(del_btn, panel_close_btn_event_cb, LV_EVENT_ALL, modify_panel);
    lv_obj_set_style_bg_color(del_btn, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_text_font(del_btn, lv_theme_get_font_large(del_btn), 0);
    lv_obj_t *btn_label = lv_label_create(del_btn);
    lv_label_set_text(btn_label, "Delete Notification");
    lv_obj_center(btn_label);
  }
}

void noti_add_btn_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * float_btn = lv_event_get_target(e);

  if(code == LV_EVENT_CLICKED) { // add new notifiaction
    lv_obj_t * noti_list = (lv_obj_t*)lv_event_get_user_data(e);
    char buf[1024];
    
    noti_item_t noti_new;
    noti_new.id = num_ids++;
    noti_new.date = pressed_date;
    noti_new.hour = 12;
    noti_new.min = 0;
    // noti_new.description = "Untitled event";
    strcpy(noti_new.description, "Untitled event");
    noti_list_vec.push_back(noti_new);
    lv_snprintf(buf, sizeof(buf), "%02d:%02d - %s", noti_new.hour, noti_new.min, noti_new.description);
    lv_obj_t *noti_list_btn = lv_list_add_btn(noti_list, NULL, buf);
    noti_list_vec[noti_list_vec.size()-1].list_btn = noti_list_btn;
    lv_obj_add_event_cb(noti_list_btn, noti_list_btn_event_cb, LV_EVENT_CLICKED, &noti_list_vec[noti_list_vec.size()-1]);
    lv_obj_move_foreground(float_btn);
    lv_obj_scroll_to_view(noti_list_btn, LV_ANIM_ON);
    updateLatestNoti();
  }
}

/* click the calendar date */
void calendar_event_cb(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_current_target(e);
  if(code == LV_EVENT_VALUE_CHANGED){ // show the day's notification
    lv_calendar_date_t *d = &pressed_date;
    lv_calendar_get_pressed_date(obj, d);
    char buf[1024];
    Serial.printf("%p %d %d %d\n", obj, d->day, d->month, d->year);
    panel = lv_obj_create(lv_layer_top());
    lv_obj_set_size(panel, 280, 200);
    lv_obj_center(panel);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    // lv_obj_set_style_bg_color(panel, lv)
    lv_obj_t *label = lv_label_create(panel);
    lv_label_set_text_fmt(label, "%s %d %d - %s", month_abbr[d->month-1], d->day, d->year, week_abbr[dayNumber(d->day, d->month, d->year)]);
    // lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    close_btn_create(panel, panel_close_btn_event_cb);

    noti_list = lv_list_create(panel);

    Serial.println("close_btn_create_over");

    lv_obj_set_size(noti_list, lv_pct(100), lv_pct(80));
    for(int i = 0; i < noti_list_vec.size(); i++){
      if(sameDay(&noti_list_vec[i].date, d)){
        lv_snprintf(buf, sizeof(buf), "%02d:%02d - %s", noti_list_vec[i].hour, noti_list_vec[i].min, noti_list_vec[i].description);
        noti_list_vec[i].list_btn = lv_list_add_btn(noti_list, NULL, buf);

        lv_obj_add_event_cb(noti_list_vec[i].list_btn, noti_list_btn_event_cb, LV_EVENT_CLICKED, &noti_list_vec[i]);
      }
    }

    /* button for adding event */
    lv_obj_t * float_btn = lv_btn_create(noti_list);
    lv_obj_set_size(float_btn, 50, 50);
    lv_obj_add_flag(float_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(float_btn, LV_ALIGN_BOTTOM_RIGHT, 0, -lv_obj_get_style_pad_right(noti_list, LV_PART_MAIN));
    lv_obj_add_event_cb(float_btn, noti_add_btn_event_cb, LV_EVENT_ALL, noti_list);
    lv_obj_set_style_radius(float_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_img_src(float_btn, LV_SYMBOL_PLUS, 0);
    lv_obj_set_style_text_font(float_btn, lv_theme_get_font_large(float_btn), 0);

  }
}

void lv_widgets(){
  Serial.println("lv_widgets() begin");
  Serial.println(LV_HOR_RES);
  // font_clock = &lv_font_montserrat_48;
  // font_clock = &arcade_64;
  // font_clock = &library3am_72;
  font_clock = &credc_48;
  font_clock_small = &credc_48;
  font_clock_small = &lv_font_montserrat_48;
  font_large = LV_FONT_DEFAULT;
  font_normal = LV_FONT_DEFAULT;
  // lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, font_normal);c:\Users\user\Downloads\credc_24.c
  
  lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), 0, font_normal);
  // lv_style_init();
  tv = lv_tileview_create(lv_scr_act());
  lv_obj_set_scrollbar_mode(tv, LV_SCROLLBAR_MODE_OFF);
  lv_obj_t *t1 = lv_tileview_add_tile(tv, 0, 0, LV_DIR_RIGHT | LV_DIR_LEFT);
  lv_obj_t *t2 = lv_tileview_add_tile(tv, 1, 0, LV_DIR_RIGHT | LV_DIR_LEFT);

  /* calendar */
  calendar = lv_calendar_create(t2);
  lv_obj_set_size(calendar, 200, 200);
  lv_calendar_set_showed_date(calendar, y, m);
  lv_calendar_set_today_date(calendar, y, m, d);
  lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);
  lv_calendar_header_arrow_create(calendar);
  lv_obj_add_event_cb(calendar, calendar_event_cb, LV_EVENT_ALL, NULL);
  /* clock */
  lv_style_init(&style_clock);
  lv_style_set_text_font(&style_clock, font_clock);

  lv_style_init(&style_clock_small);
  lv_style_set_text_font(&style_clock_small, font_clock_small);
  
  text_clock = lv_label_create(t1);
  // lv_label_set_text(text_clock, "9:46:51");
  lv_label_set_text_fmt(text_clock, "%02d:%02d:%02d", hh, mm, ss);
  lv_obj_add_style(text_clock, &style_clock, 0);
  lv_obj_align(text_clock, LV_ALIGN_TOP_MID, 0, 20);

  dmy = lv_label_create(t1);
  lv_label_set_text_fmt(dmy, "%s %d %d", month_abbr[m-1], d, y);
  lv_obj_add_style(dmy, &style_clock_small, 0);
  lv_obj_align(dmy, LV_ALIGN_CENTER, 0, 0);

  latest_noti = lv_label_create(t1);
  lv_label_set_text(latest_noti, "--");
  lv_obj_align(latest_noti, LV_ALIGN_BOTTOM_LEFT, 20, -40);
  lv_obj_set_width(latest_noti, 160);
  lv_label_set_long_mode(latest_noti, LV_LABEL_LONG_WRAP);

  temperature = lv_label_create(t1);
  lv_label_set_text(temperature, "--");
  lv_obj_align(temperature, LV_ALIGN_BOTTOM_RIGHT, -20, -20);
  lv_obj_add_style(temperature, &style_clock_small, 0);
  lv_obj_set_style_text_align(temperature, LV_TEXT_ALIGN_RIGHT, 0);

  kb = lv_keyboard_create(lv_layer_top());
  // lv_obj_add_flag(kb, LV_OBJ_FLAG_FLOATING);
  lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);

  lv_timer_t *timer = lv_timer_create(clock_timer_callback, 50, NULL);
  // Serial.println((unsigned long)timer);
}

void setup(void) {
  Serial.begin(115200);
  Serial.println(__DATE__);
  date_parse(__DATE__, &y, &m, &d);
  Serial.printf("%d %d %d\n",y,m,d);
  
  WiFi.begin(ssid, password);
  sd_setup();
  audio_setup();
  URTCLIB_WIRE.begin(20, 19);
  initDateTime();
  // rtc.set(0, 45, 19, 6, 6, 1, 2024);
  lv_init();
  tft.init();
  tft.setRotation(1);
  // touch_calibrate();
  uint16_t calData[5] = { 393, 3559, 158, 3658, 7 };
  tft.setTouch(calData);
  // tft.fillScreen(TFT_BLACK);
  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );
  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );
  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );
  lv_obj_t *label = lv_label_create( lv_scr_act() );
  lv_label_set_text( label, "Hello Ardino and LVGL!");
  lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );

  lv_widgets();
  targetTime = millis() + 1000;
  // year = 2023;
  // month = 9;

  // Serial.printf("%d %d %d %d %d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_min, tm.tm_sec);
  // Serial.println(&tm, "%A, %B %d %Y %H:%M:%S");
  Serial.println("end setup()");
}

void loop() {
  audio.loop();
  lv_timer_handler();
  delay(5);
  // return;
  // readTouch();
  if (targetTime < millis()) {
    // Set next update for 1 second later
    targetTime = millis() + 1000;

    // Adjust the time values by adding 1 second
    tick = true;
    ss++;              // Advance second
    if (ss == 60) {    // Check for roll-over
      ss = 0;          // Reset seconds to zero
      omm = mm;        // Save last minute time for display update
      mm++;            // Advance minute
      if (mm > 59) {   // Check for roll-over
        mm = 0;
        hh++;          // Advance hour
        if (hh > 23) { // Check for 24hr roll-over (could roll-over on 13)
          hh = 0;      // 0 for 24 hour clock, set to 1 for 12 hour clock
        }
      }
    }

    // month++;
    // if(month == 13) {
    //   month = 1;
    //   year++;
    // }

    // drawCalendar(month, year);



  }
}


// Function to extract numbers from compile time string
static uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}