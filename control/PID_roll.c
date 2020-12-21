#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int rkp=8, rki=1, rkd=3500;

float pid_roll(float entrada){

    struct timespec ts;
    const int SERVO_MIN_POS = 50, SERVO_MAX_POS = 110;  //SERVO_MIN_POS y SERVO_MAX_POS son los ángulos mínimo y máximo que puede manejar el servo.
    const long int TIME_FACTOR = 100000000;
    const float setpoint = 0, MAX_medida = 45;                                 //MAX_medida se utiliza para calcular el error máximo cuando el barco se inclina demasiado en el eje x
    const float dt = 4;                                                        //Diferencial de tiempo entre llamadas a la función PID

    float error=0,salidaPID=0,salidaPIDMixer=0;
    int timeChange=0,now=0;
    float derivada=0;

    //Valor máximo de salida del PID para la inclinación en el eje x, en este punto, el foil izquierdo estará a menor altura que el foil derecho
    float MAX_salidaPID = ((setpoint-(-MAX_medida))*rkp)+(dt*(setpoint-(-MAX_medida))*rki)+((setpoint-(-MAX_medida)/dt)*rkd);

    //Valor mínimo de salida del PID para la inclinación en el eje x, en este punto, el foil derecho estará a menor altura que el foil izquierdo
    float MIN_salidaPID = ((setpoint-MAX_medida)*rkp)+(dt*(setpoint-MAX_medida)*rki)+(((setpoint-MAX_medida)/dt)*rkd);


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


    //IMPLEMENTACIÓN MÍXER
    if(salidaPID>MAX_salidaPID) salidaPIDMixer = SERVO_MIN_POS;           //El servo del foil izquierdo va a recibir un ángulo de 50 º
    else if (salidaPID<MIN_salidaPID) salidaPIDMixer = SERVO_MAX_POS;     //El servo del foil izquierdo va a recibir un ángulo de 110 º

    else if (salidaPID<=MAX_salidaPID && salidaPID>=0) {
      salidaPIDMixer = 90 - ((salidaPID/MAX_salidaPID)*90);
      if(salidaPIDMixer < SERVO_MIN_POS)  salidaPIDMixer = SERVO_MIN_POS;
    }

    else if (salidaPID>=MIN_salidaPID && salidaPID<0) {
      salidaPIDMixer =  90 + ((salidaPID/MIN_salidaPID)*90);
      if(salidaPIDMixer > SERVO_MAX_POS)  salidaPIDMixer = SERVO_MAX_POS;
    }

    return salidaPIDMixer;  //Esta salida va dirigida al servo del foil izquierdo
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
