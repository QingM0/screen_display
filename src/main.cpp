#include <TFT_eSPI.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include "combined.h"

TFT_eSPI tft = TFT_eSPI();

const char *ssid = "#283446";
const char *password = "qingmo_1";
void setup()
{
  WiFi.begin(ssid, password, 6);
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.setTextSize(2);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    tft.print(".");
  }
  tft.fillScreen(TFT_WHITE); 
  weather_display();
}

void loop() {
  

}
