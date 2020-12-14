#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "PID.h"

int rkp=8,rki=1,rkd=3500;

float pid_roll(float entrada){
   
    int now=0;
    struct timespec ts;

    const float setpoint = 0;
    float error=0,salida=0,salidaMixer=0;
    int timeChange=0;
    float derivada=0;

    static int lastTime=0;
    static float integral=0,lastError=0,salidaPidMax=0;
    static int inicio=0;

    salidaPidMax = (30*rkp)+(40*30*rki)+((30/40)*rkd);

    error = (setpoint - entrada);
    clock_gettime(CLOCK_MONOTONIC, &ts);
    now = (ts.tv_sec * 1000000000 + ts.tv_nsec)/10000000;
    timeChange = now - lastTime;

    if(inicio!=0){
	integral = integral + (error * timeChange);
        derivada = (error - lastError) / timeChange;
    }

    salida = rkp*error + rki*integral + rkd*derivada;
    lastError = error;
    lastTime = now;

    if(salida>=salidaPidMax) salidaMixer = 180;
    else salidaMixer = (salida*180/salidaPidMax);

    inicio=1;

    return fabsf(salidaMixer - 180);
}

int setRollKp(int newValue){
	rkp=newValue;
	return rkp;
}
int setRollKi(int newValue){
	rki = newValue;
	return rki;
}
int setRollKd(int newValue){
	rkd = newValue;
	return rkd;
}
