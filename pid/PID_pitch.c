#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "PID.h"

int pkp=8,pki=1,pkd=3500;

float pid_pitch(float entrada){

int now=0;
    struct timespec ts;

    const float setpoint = 0;
    float error=0,salida=0,salidaMixer=0;
    int  timeChange=0;
    float derivada=0;

    static int lastTime=0;
    static float integral=0,lastError=0,salidaPidMax=0;
    static int inicio=0;

    salidaPidMax = (30*pkp)+(30*350*pki)+((30/40)*pkd);

    error = (setpoint - entrada);
    clock_gettime(CLOCK_MONOTONIC, &ts);
    now = (ts.tv_sec * 1000000000 + ts.tv_nsec)/10000000;
    timeChange = now - lastTime;

    if(inicio!=0){
        integral = integral + (error * timeChange);
        derivada = (error - lastError) / timeChange;
    }
    salida = pkp*error + pki*integral + pkd*derivada;
    lastError = error;
    lastTime = now;

    if(salida>=salidaPidMax) salidaMixer = 180;
    else salidaMixer = (salida*180/salidaPidMax);

    inicio=1;

    return salidaMixer;
}

int setPitchKp(int newValue){
	pkp=newValue;
	return pkp;
}
int setPitchKi(int newValue){
	pki = newValue;
	return pki;
}
int setPitchKd(int newValue){
	pkd = newValue;
	return pkd;
}
