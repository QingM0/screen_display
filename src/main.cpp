#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include "ArduinoUZlib.h"
#include "weather.h"

TFT_eSPI tft = TFT_eSPI();

const char *ssid = "#283446";
const char *password = "qingmo_1";

void nextweather()
{
  tft.setTextColor(TFT_WHITE);
  tft.println("current weather");

  String data = getweather();
  tft.setTextColor(TFT_GREEN);
  tft.println(data);
}
void setup()
{
  WiFi.begin(ssid, password, 6);
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    tft.print(".");
  }
  //tft.print("\nOK! IP=");
  //tft.println(WiFi.localIP());
  nextweather();
}

void loop() {}
