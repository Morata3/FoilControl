#include <stdio.h>
#include <stdlib.h>

void loggerDataCorrection(float height, float roll, float pitch, float heightAngle,float rollAngle, float pitchAngle)
{	
	FILE *logFile;

	logFile = fopen("../logs/control.log","ab+");
	fprintf(logFile,"Roll: %.2f --> Correction: %.2f\nPitch: %.2f --> Correction: %.2f \nHeight: %.2f --> Correction: %.2f\n\n",roll, rollAngle,pitch,pitchAngle,height,heightAngle);

	fclose(logFile);
}
