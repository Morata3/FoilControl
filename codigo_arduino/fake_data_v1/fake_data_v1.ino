#include "foilsim.h"

//conectar el usb del simulador mientras está corriendo el arduino
float lattitude=0,longittude=0,speedd=0;
float pitch=0,roll=0,distance=0;
float backAngle=0,leftAngle=0,rightAngle=0;
float meters_second=0;
foilsim sim(8,9);
char inByte[15];


void setup() {

speedd = 0;
Serial.begin(9600);
}

void loop() {

  speedd = sim.get_speed();
  longittude= sim.get_coord_x();
  lattitude=sim.get_coord_y();
  distance=sim.get_height();
  roll=sim.get_roll();
  pitch=sim.get_pitch();

 
 //ENVIO DE DATOS CON EL FORMATO CORRECTO AL PUERTO SERIAL
   Serial.println(String("000")+"#"+ speedd +"#"+longittude+"#"+lattitude+"#"+pitch+"#"+roll+"#"+distance);
 
   /*Serial.print("Height: "); 
   Serial.println(distance);
   Serial.print("IMU: Pitch: ");
   Serial.print(pitch);
   Serial.print(" Roll: ");
   Serial.println(roll);
   Serial.print("Speed=");
   Serial.println(speedd);
*/

   
   //Serial.println(String("00")+"-"+speedd+"-"+longitude+"-"+lattitude+"-"+pitch+"-"+roll+"-"+distance);
  //LEE DATOS SERIAL
  if(false){
  //if(Serial.available() > 0){
        Serial.readBytes(inByte, Serial.available());//DATOS RECIBIDOS POR EL SERIAL
         delay(5000);
        Serial.println(inByte);//Probar esto y mirar que devuelve(si numeros, letras, etc)
        String cadenaRecibidaSerial;
        String codigoRecibido;
        String datoRecibido;
        codigoRecibido=cadenaRecibidaSerial.substring(0,1);
        datoRecibido=cadenaRecibidaSerial.substring(2);
        
        switch(codigoRecibido.toInt()){
          case 01:
            meters_second=datoRecibido.toFloat();
          break;
          case 02:
            backAngle=datoRecibido.toFloat();
          break;
          case 03:
            rightAngle=datoRecibido.toFloat();
          break;
          case 04:
            leftAngle=datoRecibido.toFloat();
          break; 
        }        
    }
meters_second = meters_second + 0.2;
backAngle = backAngle + 0.1;
rightAngle = rightAngle + 0.1;
leftAngle = leftAngle + 0.1;
Serial.println(meters_second);
Serial.println(leftAngle);
    
   //HACER CAMBIOS EN EL MOTOR

sim.set_motor_speed(meters_second);
sim.set_back_foil_angle(backAngle);
//sim.set_front_right_foil_angle(rightAngle);
sim.set_front_left_foil_angle(leftAngle);



}
