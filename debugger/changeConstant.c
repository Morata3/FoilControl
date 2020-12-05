#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "../pid/PID.h"

int main (int argc, char *argv[]){

	bool firstStep = 1;
	bool secondStep = 1;

	int programa;
	int constante;
	int newValue;
	
	while(1){

		while(firstStep)
		{
			printf("Que programa desexa cambiar?\n");
			printf("1) Roll\n");
			printf("2) Pitch\n");
			printf("3) Height\n");
			printf("4) Salir\n");
			printf("Programa: ");
			scanf("%d",&programa);
			if(programa > 4 || programa < 1){
				printf("Opcion non valida\n");
				break;
			}
			else if(programa == 4) exit(-1);
			else firstStep = 0;
		}

		while(secondStep){
			printf("Que variable queres cambiar?\n");
			printf("1) KP\n");
			printf("2) KI\n");
			printf("3) KD\n");
			printf("4) Cambiar programa\n");
			printf("Variable: ");
			scanf("%d",&constante);
			if(constante > 4 || constante < 1){
				printf("Opcion non valida\n");
			}
			else if(constante == 4){
				firstStep = 1;
				break;
			}
			else {
				char prog[20];
				char var[20];
				sprintf(prog, "%d", programa);
			    	sprintf(var, "%d", constante);
			    	strcat(prog, var);
			    	int programaValor = atoi(prog);
			
				printf("Novo valor: ");
				scanf("%d",&newValue);

				switch(programaValor){
			
					case 11:
						setRollKp(newValue);
						break;
					case 12:
						setRollKi(newValue);
						break;
					case 13:
						setRollKd(newValue);
						break;
					case 21:
						setPitchKp(newValue);
						break;
					case 22:
						setPitchKi(newValue);
						break;
					case 23:
						setPitchKd(newValue);
						break;
					case 31:
						setHeightKp(newValue);
						break;
					case 32:
						setHeightKi(newValue);
						break;
					case 33:
						setHeightKd(newValue);
						break;
				}
			}
		}
	}
	return 0;
}
