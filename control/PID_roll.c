#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int rkp=8, rki=1, rkd=3500;

float pid_roll(float entrada){

    struct timespec ts;
    const long int TIME_FACTOR = 100000000;
    const float setpoint = 0, MAX_CORRECTION = 45;         
    const float dt = 4;

    float error=0,salidaPID=0,salidaPIDGrados=0;
    int timeChange=0,now=0;
    float derivada=0;

    float MAX_salidaPID = ((setpoint-(-MAX_CORRECTION))*rkp)+(dt*(setpoint-(-MAX_CORRECTION))*rki)+((setpoint-(-MAX_CORRECTION)/dt)*rkd);

    float MIN_salidaPID = ((setpoint-MAX_CORRECTION)*rkp)+(dt*(setpoint-MAX_CORRECTION)*rki)+(((setpoint-MAX_CORRECTION)/dt)*rkd);


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

    salidaPID = rkp*error + rki*integral + rkd*derivada;
    lastError = error;
    lastTime = now;


    //MAPEO A GRADOS
    if(salidaPID>MAX_salidaPID || salidaPID<MIN_salidaPID) salidaPIDGrados = MAX_CORRECTION;          
    else if (salidaPID<=MAX_salidaPID && salidaPID>=0) {
      salidaPIDGrados = ((salidaPID/MAX_salidaPID)*MAX_CORRECTION);
    }

    else if (salidaPID>=MIN_salidaPID && salidaPID<0) {
      salidaPIDGrados = -((salidaPID/MIN_salidaPID)*MAX_CORRECTION);
    }

    return salidaPIDGrados;
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
