#include "MPU6050_SENSOR.h"

MPU6050_SENSOR::MPU6050_SENSOR()
{
}


bool MPU6050_SENSOR::init()
{
  Serial.println("Initializing MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_16G))
    Serial.println("Error with MPU6050");
  Serial.println("MPU6050 READY!");
  mpu.calibrateGyro();
  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);
  mpu.setDHPFMode(MPU6050_DHPF_5HZ);

  mpu.setFreeFallDetectionThreshold(17);
  mpu.setFreeFallDetectionDuration(2); 
  //attachInterrupt(0, doInt, RISING); 
  return true;
}

int MPU6050_SENSOR::getState()
{
  // Read normalized accelaration values
  Vector normAccel = mpu.readNormalizeAccel();

  // Read nomalized gyro values
  Vector norm = mpu.readNormalizeGyro();

  // Time is used for pitch, roll and yaw calculations
  timer = millis();
  
  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;
  
  // Print data in serial monitor
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.print(normAccel.ZAxis);
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);  
  Serial.print(" Yaw = ");
  Serial.print(yaw);

  
 return 1; 
}

bool MPU6050_SENSOR::setState()
{
  Serial.println("Changed the state");
  return true;
}
