#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "PID.h"

int hkp=8,hki=1,hkd=3500;

float pid_height(float entrada){


    int now=0;
    struct timespec ts;

    const float setpoint = 350;
    float error=0,salida=0,salidaMixer=0;
    int timeChange=0;
    float derivada=0;

    static int lastTime=0;
    static float integral=0,lastError=0,salidaPidMax=0;
    static int inicio=0;

    salidaPidMax = (350*hkp)+(40*350*hki)+((350/40)*hkd);

    error = (setpoint - entrada);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    now = (ts.tv_sec * 1000000000 + ts.tv_nsec)/10000000;
    timeChange = now - lastTime;

    if(inicio!=0){
        integral = integral + (error * timeChange);
        derivada = (error - lastError) / timeChange;
    }
    salida = hkp*error + hki*integral + hkd*derivada;
    lastError = error;
    lastTime = now;

    if(salida>=salidaPidMax) salidaMixer = 180;
    else salidaMixer = (salida*180/salidaPidMax);

    inicio=1;

    return fabsf(salidaMixer - 180);
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

