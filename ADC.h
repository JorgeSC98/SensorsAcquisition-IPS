#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus

#endif
#define _XTAL_FREQ 8000000
void ADC_Lectura(void);
void ADC_Init(uint8_t entradas_analogicas, uint8_t Vref, uint8_t Clock, uint8_t ADQT, uint8_t justificacion, uint8_t estado);
int Leer_Canal_ADC(uint8_t Canal);
int ADC_Lectura_Sensores(int n);
void Concat_Value(char id[2],int Lectura0,int Lectura1, int Lectura2,int Lectura3,int Lectura4, int Lectura5, int Lectura6, int Lectura7);
int SENSOR_0;
int SENSOR_1;
int SENSOR_2;
int SENSOR_3;
int SENSOR_4;
int SENSOR_5;
int SENSOR_6;
int SENSOR_7;
int Lectura;
int LecturaFiltro;
long Suma;
char cadena[4];
char result[33];
int ADC_InsertBits(char Bmenos, char Bmas);
int ADC_LecturaFiltro(int n,uint8_t Canal);
void changeInt(int value, char *str);
void strreverse(char* begin, char* end);
#ifdef	__cplusplus

#endif

#endif