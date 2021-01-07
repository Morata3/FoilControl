#include <SoftwareSerial.h>
#include "Adafruit_VL53L0X.h"
#include <TinyGPS++.h>
#include <SPI.h>
#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h>
MPU6050 accelgyro;
I2Cdev   I2C_M;

uint8_t buffer_m[6];

float pitch,roll,distance;
float backAngle,leftAngle,rightAngle;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t   mx, my, mz;

Servo myservo;  // crea el objeto servo
Servo myservo2;  // crea el objeto servo
Servo myservo3;  // crea el objeto servo


char inByte[25];   

float heading;
float tiltheading;

float Axyz[3];
float Mxyz[3];


#define sample_num_mdate  5000    

static float mx_centre = 0;
static float my_centre = 0;
static float mz_centre = 0;

float lattitude,longittude,speedd;
SoftwareSerial gpsSerial(4,3);//rx,tx
TinyGPSPlus gps;                      
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup()
{
   myservo.attach(3,50,110);  // vincula el servo al pin digital 3
   myservo2.attach(4,50,110);  // vincula el servo al pin digital 4
   myservo3.attach(5,50,110);  // vincula el servo al pin digital 5
  gpsSerial.begin(9600); // connect gps sensor
  Serial.begin(9600);  // the Serial port of Arduino baud rate.
  delay(500);

  Serial.println("Booting...");
    //set_angle_back_foil(90);
    while (! Serial) {
  delay(1);
  }
 
  if (!lox.begin()) {
  Serial.println("Failed to boot VL53L0X");
  while(1);
  }

}
 
void loop()
{
  VL53L0X_RangingMeasurementData_t measure;

  delay(1000);
    
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) { 
  distance=measure.RangeMilliMeter;
  }
    
  delay(100);
  
   getAccel_Data();
   getTiltHeading();        


  //while(1) ... break
   while (gpsSerial.available() > 0)
   { gps.encode(gpsSerial.read()); }
  
    if (gps.location.isUpdated())
    {
    lattitude=gps.location.lat();
    longittude=gps.location.lng();
    speedd = gps.speed.kmph();
    }

  
//LEE DATOS SERIE
 if ( Serial.available()) {
    String serialResponse;
    String prefijo;
    String dato;
    String cadena;

    serialResponse = Serial.readStringUntil('\r\n');

    // Convert from String Object to String.
    Serial.readBytes(inByte, Serial.available());
    Serial.flush();
    char buf[sizeof(inByte)];
    serialResponse.toCharArray(buf, sizeof(buf));
    char *p = buf;
    char *str;

    while ((str = strtok_r(p, "#", &p)) != NULL){ // delimiter is the semicolon
      cadena = str;
      Serial.println(cadena);
      
      prefijo = cadena.substring(0,2);
      dato = cadena.substring(2);
      dato.trim();


      switch(prefijo.toInt()){
          case 01:
            leftAngle=dato.toFloat();
            set_angle_left_foil((int)leftAngle);
          break;
          case 02:
            rightAngle=dato.toFloat();
            set_angle_right_foil((int)rightAngle);
            break;
          case 03:
            backAngle = dato.toFloat();
            set_angle_back_foil((int)backAngle);
          break;
          default:
              Serial.flush();
      //      Serial.println("PARAMETROS INCORRECTOS");
          break;
      }

      
    }
  } 

 //ENVIO DE DATOS CON EL FORMATO CORRECTO AL PUERTO SERIAL
 //Serial.println(speedd);
    Serial.flush();
    Serial.print("000#");
      Serial.print(speedd);
      Serial.print("#");
       Serial.print(pitch);
       Serial.print("#");
       Serial.print(roll);
       Serial.print("#");
       Serial.println(distance);   
  

  

  
}

void set_angle_back_foil(int angle)
{
  if(angle > 120) angle = 110;
  if(angle < 50) angle=50;
  //varia la posicion de 0 a 180
  
  myservo.write(angle);

  
}

void set_angle_right_foil(int angle)
{ 
  
  if(angle > 120) angle = 110;
  if(angle < 50) angle=50;
  myservo2.write(angle); 

  
}

void set_angle_left_foil(int angle)
{
  if(angle > 120) angle = 110;
  if(angle < 50) angle=50;
  myservo3.write(angle); 

  
}
 
void getAccel_Data(void)
{
  accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  Axyz[0] = (double) ax / 16384;
  Axyz[1] = (double) ay / 16384;
  Axyz[2] = (double) az / 16384;
}



void getTiltHeading(void)
{
   pitch = asin(-Axyz[0]);
   roll = asin(Axyz[1]/cos(pitch));
}
