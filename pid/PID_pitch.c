#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>


int main(){

    const int setpoint=80,kp=2,ki=3,kd=1;
    float  entrada=0,inicio=0,flag=1,lastError=0,error=0,integralError=0,derivadaError=0,salida=0,dt=0.001;

    while(flag){

      srand(time(NULL));
      entrada = 75 + rand() % 11;

      printf("\nPitch medido por el sensor => %f\n",entrada);

      error = (setpoint - entrada);
      if(inicio!=0){
        integralError = integralError + (error * dt);
        derivadaError = (error - lastError) / dt;
      }
      salida = kp*error + ki*integralError + kd*derivadaError;
      lastError = error;

      printf("\nSalida controlador PID... => %f\n",salida);
      inicio=1;
      sleep(dt);

    }


    return 0;
}
