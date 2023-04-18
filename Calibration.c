/*
 * File:   Calibration.c
 * Author: saenz
 *
 * Created on 18 de febrero de 2022, 11:49 AM
 */


#include <xc.h>
#include "Conf.h"
#include "ADC.h"
#include "UART.h"
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#include <math.h>
#include "Calibration.h"
#include "Pot.h"
#include "EEPROM.h"

void Calibration_Init() {
/*
 * 1. DECLARAR PINES DE LOS POTENCIOMETROS 
 * 
 * 
 * 2. DECLARAR PUERTOS COMO SALIDA PARA LOS POTENCIOMETRO 
 * 3.LEER Valor de sensor ADC
 * 4.COMPARAR VALORES DEL ADC CON VALOR PICO DE SATURACION
 * 5. DECIDIR SI EL POTENCIOMETRO REQUIERE INCREMENTAR O DECREMENTAR SU VALOR 
 * 6. CICLO DE COMPARACION HASTA ALCNZAR NIVEL DE SAUTRACION 
 * 7. GUARDAR EL VALOR DEL POT.
 * 8. CONTINUAR CON SIGUIENTE SENSOR
 * 
 *  INC: Changing resistor command
    U/D: UP / Down. Adjusting resistor
    CS: Chip Select. Active LOW
 */
    Pot_Init();
}
void Calibration_Run(){
    //CALIBRATION_REFERENCE=reference;
    CALIBRATION_RUN= 1;
    CALIBRATION_START='H';
    SENSOR_ID=0;
    SENSOR_I=0;
    Pot_Value=0;
    while(CALIBRATION_RUN){
        if (SENSOR_ID<8){
        CALIBRATION_START=USART_RxC();;//USART_RxC();//RECIBIR Y/N, PARA TIPO DE CALIBRACION
        if (CALIBRATION_START=='y'){
           for (int i=0; i<8; i++){
          Calibration_Automatic(SENSOR_ID);
           //changeInt(Pot_Value,result);
           //USART_TxS(result);
           SENSOR_ID++;}
           USART_TxS("d\n");}
        else if(CALIBRATION_START=='n'){
           Calibration_Set(SENSOR_ID);
           //USART_TxSS(Pot,2);
           Direction=SENSOR_ID;
           Direction=EEPROM_Decodificacion_Memoria(Direction);
           Escritura_Memoria(Direction,Pot);
           __delay_ms(1);
           USART_TxS("d");
           SENSOR_ID++;}
        }
        else {CALIBRATION_RUN=0;}
    }
    //SE TERMINO CALIBRACION
}
void Calibration_Automatic(char s){
    Direction=EEPROM_Decodificacion_Memoria(s);
    Pot_Value=Lectura_Memoria(Direction);
    Pot_Set(s,Pot_Value);
    
}
int Calibration_Auto(char s){
    Pot_Reset(s);
    Pot_Value=0;
    int Data=0;
    flag=1;
    while(flag){
    for (int i=0;i<100;i++){//INCREMENTOS PARA CALIBARCION
        Pot_Increase(s,1);
        if (Pot_Value>99){
            Pot_Value=100;}
        else {
            Pot_Value++;}
        Data=ADC_LecturaFiltro(10,s);
        if (Data>Range_Low && Data<Range_High){
             s++;  
             flag=0;
             break;}
    }
    for (int i=0;i<100;i++){//DECREMENTO PARA CALIBARCION
        Pot_Decrease(s,1);
        if (Pot_Value<1){
            Pot_Value=0;}
        else {
            Pot_Value--;}
        Data=ADC_LecturaFiltro(10,s);
        if (Data>Range_Low && Data<Range_High){
             s++;  
             flag=0;
             break;}
    }  
    }
    return Pot_Value;
    
}
void Calibration_Set(char s){
    Pot_Value=0;
    while(Pot_Value==0){
      USART_RxS (2, Pot );//Checar bien como leer string
      Pot_Value = atoi(Pot);     //Convertir a Int la lectura
    }
    Pot_Set(s,Pot_Value);
}