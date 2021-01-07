#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int hkp=8, hki=1, hkd=3500;

float pid_height(float entrada){

    struct timespec ts;
    const int SERVO_MIN_POS = 50, SERVO_MAX_POS = 110;                          //SERVO_MIN_POS y SERVO_MAX_POS son los ángulos mínimo y máximo que puede manejar el servo.
    const long int TIME_FACTOR = 100000000;
    const float setpoint = 0.35, MAX_medida = 0.5;                              //MAX_medida se utiliza para calcular el error máximo cuando el barco se eleva demasiado
    const float dt = 4;                                                         //Diferencial de tiempo entre llamadas a la función PID

    float error=0,salidaPID=0,salidaPIDMixer=0;
    int timeChange=0,now=0;
    float derivada=0;
    float MAX_salidaPID = (setpoint*hkp)+(dt*setpoint*hki)+((setpoint/dt)*hkd);                                        //Valor máximo de salida del PID
    float MIN_salidaPID = ((setpoint-MAX_medida)*hkp)+(dt*(setpoint-MAX_medida)*hki)+(((setpoint-MAX_medida)/dt)*hkd); //Valor mínimo de salida del PID

    static int lastTime=0;
    static float integral=0,lastError=0;
    static int inicio=0;

    error = (setpoint - entrada);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    now = (ts.tv_sec * 1000000000 + ts.tv_nsec)/TIME_FACTOR;

    timeChange = now - lastTime;

    if(inicio == 0) {
      timeChange = dt;
      inicio = 1;
    }

    integral = integral + (error * timeChange);
    derivada = (error - lastError)/timeChange;

    salidaPID = hkp*error + hki*integral + hkd*derivada;
    lastError = error;
    lastTime = now;


    //IMPLEMENTACIÓN MÍXER
    if(salidaPID>MAX_salidaPID) salidaPIDMixer = SERVO_MIN_POS;           //Los servos van a recibir un ángulo de 50 º
    else if (salidaPID<MIN_salidaPID) salidaPIDMixer = SERVO_MAX_POS;     //Los servos van a recibir un ángulo de 110 º

    else if (salidaPID<=MAX_salidaPID && salidaPID>=0) {
      salidaPIDMixer = 90 - ((salidaPID/MAX_salidaPID)*90);
      if(salidaPIDMixer < SERVO_MIN_POS)  salidaPIDMixer = SERVO_MIN_POS;
    }

    else if (salidaPID>=MIN_salidaPID && salidaPID<0) {
      salidaPIDMixer =  90 + ((salidaPID/MIN_salidaPID)*90);
      if(salidaPIDMixer > SERVO_MAX_POS)  salidaPIDMixer = SERVO_MAX_POS;
    }

    return salidaPIDMixer;  //Esta salida va dirigida a los tres servos
}

int setHeightKp(int newValue){
	hkp=newValue;
	return hkp;
}
int setHeightKi(int newValue){
	hki = newValue;
	return hki;
}
int setHeightKd(int newValue){
	hkd = newValue;
	return hkd;
}
