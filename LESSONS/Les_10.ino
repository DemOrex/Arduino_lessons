#include <TVout.h>
#include <fontALL.h>


#include "DHT.h" // подключаем библиотеку для датчика

DHT dht(2, DHT11); // сообщаем на каком порту будет датчик



TVout TV;


void setup() {
  TV.begin(PAL,120,96);
  TV.select_font(font6x8);

  dht.begin();
  randomSeed(analogRead(2));
}

void loop() {
  
float h = dht.readHumidity();
float t = dht.readTemperature();
  
  
  TV.clear_screen();
  TV.println("HELLO \nI am the Arduino\n");
  TV.delay(1500);
  TV.println("I will show you\nthe temperature and humidity\nin your home\n");
  TV.delay(2500);
  
  TV.clear_screen();
  TV.print(16,40,"TEMPERATURE");
  TV.print(28,48,t);
  TV.delay(2000);
  
  
  TV.clear_screen();
  TV.print(16,40,"HUMIDITY");
  TV.print(28,48,h);
  TV.delay(2000);
  
}
