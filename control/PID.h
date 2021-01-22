#ifndef PID_HEADER
#define PID_HEADER

#define domainHeight 0
#define domainImu 1
#define domainGps 2
#define domainPid 3

float pid_pitch(float entrada);
float pid_roll(float entrada);
float pid_height(float entrada);

int setRollKp(int newValue);
int setRollKi(int newValue);
int setRollKd(int newValue);

int setPitchKp(int newValue);
int setPitchKi(int newValue);
int setPitchKd(int newValue);

int setHeightKp(int newValue);
int setHeightKi(int newValue);
int setHeightKd(int newValue);

#endif
