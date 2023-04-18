#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus

#endif

char EEPROM_Rx(char direccion);
void EEPROM_Tx(char direccion, char dato);
char EEPROM_Decodificacion_Memoria(char direccion);
int Lectura_Memoria(char direccion);
void Escritura_Memoria(char direccion, char string_pot[]);
//void EEMPROM_Init();
char data;
char potenciometro[2];
int Calibration_value;

#ifdef	__cplusplus

#endif

#endif	