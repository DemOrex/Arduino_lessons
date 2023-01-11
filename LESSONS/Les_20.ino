#include "DHT.h" // подключаем библиотеку для датчика

DHT dht(2, DHT11); // сообщаем на каком порту будет датчик

void setup() // процедура setup

{

dht.begin(); // запускаем датчик влажности DHT11

Serial.begin(9600); // подключаем монитор порта
Serial.println("DHT TEST"); // пишем один раз

}

void loop() // процедура loop

{

// считываем температуру (t) и влажность (h) каждые 250 мс

float h = dht.readHumidity();
float t = dht.readTemperature();

// выводим температуру (t) и влажность (h) на монитор порта

Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C");

}
