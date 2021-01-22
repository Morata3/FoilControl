#include <stdio.h>
#include <stdlib.h>

void loggerDataCorrection(float height, float roll, float pitch, float heightAngle,float rollAngle, float pitchAngle)
{	
	FILE *logFile;

	logFile = fopen("../logs/control.log","ab+");
	fprintf(logFile,"[CONTROL]: Roll: %.2f --> Correction: %.2f\n[CONTROL]: Pitch: %.2f --> Correction: %.2f \n[CONTROL]: Height: %.2f --> Correction: %.2f\n\n",roll, rollAngle,pitch,pitchAngle,height,heightAngle);

	fclose(logFile);
}
