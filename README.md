# Esp8266_NTP_Clock_Weather
Esp8266 NTP时钟和气象站(使用和风天气API)

![scr1](https://github.com/inramento/Esp8266_NTP_Clock_Weather/raw/master/Pictures/screen1.jpg)


## 前言
根据ESP8266 weather station demo修改而成， 修改了部分显示样式，主要使用了和风天气API，方便国内用户使用，并且可预报未来三天的最低/高气温，原版的openweathermap免费版API是不行的。

##



# 教程
## 材料

Esp8266 mini D1

1.3英寸Oled屏幕(SH1106/SSD1306)

DS18B20 / 4.7k 上拉电阻

3D打印外壳

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

3.焊接/连线

我的接线方法:(你也可以按你的喜好来,注意修改程序中的接口信息)



