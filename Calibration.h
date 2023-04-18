#ifndef Calibration_H
#define	Calibration_H

#ifdef	__cplusplus
extern "C" {
#endif
#define _XTAL_FREQ 8000000
   
    

void Calibration_Init();
void Calibration_Run();
int Calibration_Auto(char s);
void Calibration_Automatic(char s);
void Calibration_Set(char s);
int SENSOR_VALUE;
int CALIBRATION_REFERENCE;
bool CALIBRATION_RUN;
bool flag;
char CALIBRATION_START='H';
char SENSOR_ID=0;
char SENSOR_I=0;
int Pot_Value;
char Pot[2];
char Direction;
int Range_Low=730;
int Range_High=770;
#ifdef	__cplusplus
}
#endif

#endif