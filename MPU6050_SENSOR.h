#ifndef MPU6050_SENSOR_H
#define MPU6050_SENSOR_H
#include <Arduino.h>
//#include "Sensor.h"
#include <MPU6050.h>//Library for the  6 axis accelerometer and gyro


class MPU6050_SENSOR
{
  private:
  // Pitch, Roll and Yaw values
    float pitch = 0;
    float roll = 0;
    float yaw = 0;
    unsigned long timer = 0;
    float timeStep = 0.01;
    MPU6050 mpu;

    //Free fall variables
    boolean ledState = false;
    boolean freefallDetected = false;
    int freefallBlinkCount = 0;
  
  public: 
    MPU6050_SENSOR();
    int getState();
    bool init();
    bool setState();
};

#endif
