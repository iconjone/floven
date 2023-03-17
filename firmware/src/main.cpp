// #include <ESP8266WiFi.h>
#include <Arduino.h>
#include <WiFi.h>
#include <Adafruit_NeoPixel.h>
#include "nvs_flash.h"


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        33 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 2 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
    Serial.begin(115200);
  // pinMode(ovenPin, OUTPUT);
// WiFi.disconnect(true);
// ESP_ERROR_CHECK(nvs_flash_erase());
// nvs_flash_init();
Serial.println("gets here");
pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    WiFi.mode(WIFI_STA);
    // WiFi.mode(WIFI_AP);

    // WiFi.softAP("rogo");
    WiFi.begin("TheWall", "137udnC025");
  //   //   MDNS.begin("floven");
WiFi.setTxPower(WIFI_POWER_8_5dBm); 
  //    Serial.println("Connecting to WiFi");
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.print('.');
  //   delay(500);
  // }
  // Serial.println(WiFi.localIP());

    //     WiFi.begin("Vibin", "vibinon1");

}

void loop() {
 pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(20, 10, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}