#ifndef DS18B20_H
#define DS18B20_H

#include "Arduino.h"
#include <OneWire.h>

#define SEARCH_ROM 0xF0
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define ALARM_SEARCH 0xEC
#define CONVERT_T 0x44
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL 0xB8
#define READ_POWER_SUPPLY 0xB4
#define MODEL_DS1820 0x10
#define MODEL_DS18S20 0x10
#define MODEL_DS1822 0x22
#define MODEL_DS18B20 0x28
#define SIZE_SCRATCHPAD 9
#define TEMP_LSB 0
#define TEMP_MSB 1
#define ALARM_HIGH 2
#define ALARM_LOW 3
#define CONFIGURATION 4
#define CRC8 8
#define RES_9_BIT 0x1F
#define RES_10_BIT 0x3F
#define RES_11_BIT 0x5F
#define RES_12_BIT 0x7F
#define CONV_TIME_9_BIT 94
#define CONV_TIME_10_BIT 188
#define CONV_TIME_11_BIT 375
#define CONV_TIME_12_BIT 750

class DS18B20 {
    public:
        DS18B20(uint8_t pin);
        uint8_t select(uint8_t address[]);
        uint8_t selectNext();
        uint8_t selectNextAlarm();
        void resetSearch();
        float getTempC();
        float getTempF();
        uint8_t getResolution();
        void setResolution(uint8_t resolution);
        uint8_t getPowerMode();
        uint8_t getFamilyCode();
        void getAddress(uint8_t address[]);
        void doConversion();
        uint8_t getNumberOfDevices();
        uint8_t hasAlarm();
        void setAlarms(int8_t alarmLow, int8_t alarmHigh);
        int8_t getAlarmLow();
        void setAlarmLow(int8_t alarmLow);
        int8_t getAlarmHigh();
        void setAlarmHigh(int8_t alarmHigh);
        void setRegisters(int8_t lowRegister, int8_t highRegister);
        int8_t getLowRegister();
        void setLowRegister(int8_t lowRegister);
        int8_t getHighRegister();
        void setHighRegister(int8_t highRegister);
    private:
        OneWire oneWire;
        uint8_t globalResolution;
        uint8_t globalPowerMode;
        uint8_t numberOfDevices;
        uint8_t selectedAddress[8];
        uint8_t selectedScratchpad[SIZE_SCRATCHPAD];
        uint8_t selectedResolution;
        uint8_t selectedPowerMode;
        uint8_t searchAddress[8];
        uint8_t lastDiscrepancy;
        uint8_t lastDevice;
        uint8_t readScratchpad();
        void writeScratchpad();
        uint8_t sendCommand(uint8_t romCommand);
        uint8_t sendCommand(uint8_t romCommand, uint8_t functionCommand, uint8_t power = 0);
        uint8_t oneWireSearch(uint8_t romCommand);
        uint8_t isConnected(uint8_t address[]);
        void delayForConversion(uint8_t resolution, uint8_t powerMode);
};

#endif
