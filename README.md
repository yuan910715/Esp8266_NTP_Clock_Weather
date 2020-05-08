# Esp8266_NTP_Clock_Weather
Esp8266 NTP时钟和气象站(使用和风天气API) 使用NTP网络时间 不用对时永远准确  
![scr1](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/screen1.jpg)

![scr2](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/screen2.jpg)

![scr3](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/screen3.jpg)

## 材料
![list](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/list.jpg)

Esp8266 mini D1  
1.3英寸Oled屏幕(SH1106/SSD1306)  
DS18B20 / 4.7k 上拉电阻  
3D打印外壳  
## 程序
根据ESP8266 weather station demo修改而成， 修改了部分显示样式，主要使用了和风天气API，方便国内用户使用，并且可预报未来三天的最低/高气温，原版的openweathermap免费版API是不行的，增加了DS18B20温度传感器右下角显示室内实时温度。  
## Arduino 库
1.自行设置安装ESP8266开发板  
进入首选项（Preferences），找到附加开发板管理器地址（Additional Board Manager URLs），并在其后添加如下信息：  
http://arduino.esp8266.com/stable/package_esp8266com_index.json  
![pic2](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/pic2.png)  
点击工具 - 开发板 - 开发板管理器  
搜索ESP8266并安装。  
![pic1](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/pic1.png)  

2.Library Manager中安装  
ArduinoJson库  用于解析和风天气API response的JSON  
DS18B20库      用于读取DS18B20的温度,检测房间内实时温度  
ESP8266 and ESP32 OLED driver for SSD1306 displays库   用于驱动OLED屏幕显示内容  
OneWire库      用于连接DS18B20

## 焊接/连线  
我的接线方法:(你也可以按你的喜好来,注意修改程序中的接口信息)  



## 3D打印外壳 
模型是别人做的 作者Qrome 
一个是0.96英寸版本的 https://www.thingiverse.com/thing:2884823  
一个是1.3英寸版本的 https://www.thingiverse.com/thing:2934049  
他的项目是用于显示3D打印机打印状态的https://github.com/Qrome/printer-monitor  

## 程序  
需要修改的地方：  
你的wifissid 密码  
// WIFI  
const char* WIFI_SSID = "";  
const char* WIFI_PWD = "";  

DS18B20 数据端(中间角) 连接的位置  
DS18B20 ds(D7);  
DSB18B20地址 用DS18B20库的example程序可获取到  
uint8_t address[] = {0x28,0x44,0x9B,0x16,0xA8,0x01,0x3C,0x4B};

时区以及夏令时设置  
#define TZ              -8       // (utc+) TZ in hours  
#define DST_MN          0      // use 60mn for summer time in some countries  

第二屏实时天气 第三屏预报的更新频率  
const int UPDATE_INTERVAL_SECS = 20 * 60; // Update every 20 minutes  online weather  
DS18B20更新频率  
const int UPDATE_CURR_INTERVAL_SECS = 10; // Update every 10 secs DS18B20  
NTP时间更新频率  
const int UPDATE_NTP_INTERVAL_SECS = 24*60*60; // Update every day  
OLED地址以及管脚信息  
const int I2C_DISPLAY_ADDRESS = 0x3c;  
#if defined(ESP8266)  
const int SDA_PIN = D2;  
const int SDC_PIN = D5;  
#endif  

和风天气KEY 城市ID 自行去https://dev.heweather.com/ 注册  
const char* HEFENG_KEY="";   
const char* HEFENG_LOCATION="";  
