#ifndef PID_HEADER
#define PID_HEADER

#define domainHeight 0
#define domainImu 1
#define domainGps 2
#define domainPid 3



float pid_pitch(float entrada);
float pid_roll(float entrada);
float pid_height(float entrada);

#endif /*PID_HEADER*/
