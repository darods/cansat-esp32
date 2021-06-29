/*
 * Autor: Daniel Alejandro Rodriguez
 * Año: 2021
 * Universidad Distrital Francisco José de Caldas
 * Grupo de investigación LIDER
 * Semillero de investigación ATL
 */
const int buzzer = 15; //buzzer to arduino pin 9
 
 //RGB Led
#define LEDR 27
#define LEDB 26
#define LEDG 25

#define R_channel 0
#define G_channel 1
#define B_channel 2

#define pwm_Frecuency 5000
#define pwm_resolution 8

// Liberías
//#include "MPU9250.h" // Acelerometro usado: MPU9250
 // librerías para sensor DTH11
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LoRa.h>
#include <SPI.h>

// Sensores conectados por pin digital
#define DHTPIN    4  // Pin digital conectado de ESP32 a data en dth11 
#define DHTTYPE    DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);

//  BMP280 snesor library
#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp; // I2C

// LoRa conf
#define ss 5
#define rst 14
#define dio0 2

// GPS libaries
#include "types.h"
#include "TinyGPS++.h";
#include "HardwareSerial.h";
TinyGPSPlus gps;
HardwareSerial SerialGPS(1);
 
// Sensores concectador por I2C
//MPU9250 IMU(Wire,0x68); // Dirección I2C 0x68
int status;

void setup() {
  Serial.begin(115200);
  while(!Serial) {}
  RGBLed_init();
  buzzer_init(); 
  dth11_init(); // inizalization dt11
  //mpu9250_init(); // inizalization mpu9250
  //bmp280_init(); // inizalization bmp280
  //gps_init(); // inizalization GPS
  buzzer_success();
  LoRa_init();
  RGBLed_success();
  
  

}

void loop() {
  String packet="";
   // read the sensor
  
  
  packet+=dth11_data();
  //packet+= bmp280_data();
  //gps_data();
  sendPacket(packet);
  Serial.println(F("-------------------------------------------------------------"));
  delay(10000);
}
