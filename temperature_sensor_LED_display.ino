#include <Adafruit_NeoPixel.h>
#include "DHT.h"

#define PIN            6

#define NUMPIXELS      32

#define DHTPIN 2   

#define DHTTYPE DHT11  

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
DHT dht(DHTPIN, DHTTYPE);

int delayval = 2000; //delay 2 seconds

void setup() {
  Serial.begin(9600);

  dht.begin();
  pixels.begin();
  
}

void loop() {
    float farenheit = dht.readTemperature(true);
      
    if (isnan(farenheit)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

      Serial.print(farenheit);
      Serial.println(" *F\t");

    if(farenheit < 42){

      for(int i=0;i<NUMPIXELS;i++){
        
        pixels.setPixelColor(i, pixels.Color(0,0,5)); // LEDs display dark blue
      }
    }
    else if(farenheit >= 42 && farenheit < 52){
    

      for(int i=0;i<NUMPIXELS;i++){

        pixels.setPixelColor(i, pixels.Color(1,4,5)); // LEDs display light blue
      }
    }

    else if(farenheit >= 52 && farenheit < 62){

      for(int i=0;i<NUMPIXELS;i++){

        pixels.setPixelColor(i, pixels.Color(0,7,2)); // LEDs display green
      }
    }
    else if(farenheit >= 62 && farenheit < 72){

      for(int i=0;i<NUMPIXELS;i++){

        pixels.setPixelColor(i, pixels.Color(5,4,1)); // LEDs display yellow
      }
    }
    else if(farenheit >= 72 && farenheit < 82){
    

      for(int i=0;i<NUMPIXELS;i++){

        pixels.setPixelColor(i, pixels.Color(5,2,0)); //LEDs display orange
      }
    }
    else if(farenheit > 82){
    

      for(int i=0;i<NUMPIXELS;i++){

        pixels.setPixelColor(i, pixels.Color(5,0,0)); // LEDs display red
      }
    }
    pixels.show(); 
    delay(delayval);
}
