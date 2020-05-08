
#pragma once
#include <ArduinoJson.h>

typedef struct HeFengCurrentData {

  String cond_txt;
  String fl;
  String tmp;
  String hum;
  String wind_sc;
  String iconMeteoCon;
  
} HeFengCurrentData;
typedef struct HeFengForeData {
  String datestr;
  String tmp_min;
  String tmp_max;
  String iconMeteoCon;
  
} HeFengForeData;
class HeFeng {
  private:
     String getMeteoconIcon(String cond_code);   
  public:
    HeFeng();
    void doUpdateCurr(HeFengCurrentData *data, String key,String location);
    void doUpdateFore(HeFengForeData *data, String key,String location);
  
};
