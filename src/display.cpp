#include "combined.h"
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include "Fonts/MiSans_20.h"
#include "Fonts/QWeathe_20.h"

// 声明 tft
extern TFT_eSPI tft;

void weather_display()
{
    tft.loadFont(MiSans_20);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.setCursor(10, 10);
    tft.println("现在天气");

    ArduinoJson::V704PB2::JsonDocument weatherData = getweather();

    tft.setCursor(10, 30);
    String text = weatherData["now"]["text"].as<String>();
    tft.println("天气: " + text);

    tft.setCursor(10, 50);
    String temp = weatherData["now"]["temp"].as<String>();
    tft.println("温度: " + temp + "度");

    tft.setCursor(10, 70);
    String windSpeed = weatherData["now"]["windSpeed"].as<String>();
    tft.println("风速: " + windSpeed + "km/h");

    tft.unloadFont();
}