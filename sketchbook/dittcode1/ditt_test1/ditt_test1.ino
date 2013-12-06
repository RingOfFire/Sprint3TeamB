/*
not stock BOAT
*/



//#include "Motor.h" // for new kits Oct 2013
#include "MotorRobotBase.h" // for stock robots ONLY
#define Motor MotorRobotBase // for stock robots ONLY
#include "Sensor.h"

void forward (Motor &m1, Motor &m2) 
{
  int speed; 
  // speed up
  for (speed = 0; speed <= 255; speed += 5) {
    m1.forward(speed);
    m2.forward(speed);
    delay(30); 
  }
  // speed down
  for (speed = 255; speed >= 0; speed -= 5) {
    m1.forward(speed);
    m2.forward(speed);
    delay(30);
  }
}


Motor right_motor(Motor::MOTOR_1);
Motor left_motor(Motor::MOTOR_2);
Sensor light(Sensor::SENSOR_0);


void setup () 
{ 
  int ii;
  int current_level;
  
  Serial.begin(9600);
  
  right_motor.setup();
  left_motor.setup();
  light.setup();
  light.set_mode(Sensor::SIMPLEX_MODE);
  light.calibrate();

} 

void loop () 
{
  int brightness = 1023;
  light.read(brightness);
  
  left_motor.forward(100);
  right_motor.forward(100);
  
  if (micros()>=10000000) //added 0
  {
    left_motor.forward(0);
    right_motor.forward(0);
    
    delay(50);
  }
  


  /*
  int light_level = 1023;
  char light_str[255];
  
  light.read(light_level);

//light_level = light.get_light_level();
  if (light_level < (light.get_light_level() - 20)) {
     Serial.write("low\n"); 
     left_motor.forward(0);
     right_motor.forward(0);
  }  else {
     left_motor.reverse(50);
     right_motor.reverse(50);
     Serial.write("normal\n");     
  }
  */
  delay(500);
}



