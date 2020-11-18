#ifndef PID_HEADER
#define PID_HEADER

#define domainImu 0
#define domainHeight 1
#define domainGps 2
#define domainPid 3



float pid_pitch(float entrada);
float pid_roll(float entrada);
float pid_height(float entrada);

#endif /*PID_HEADER*/
