/*
 * File:   newmain.c
 * Author: saenz
 *
 * Created on 17 de febrero de 2022, 01:11 PM
 */

#include <xc.h>
#include "Conf.h"
#include "ADC.h"
#include "UART.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "Calibration.h"
#include "Pot.h"
#include "EEPROM.h"
/*
 * TRISX: Escribiendo en cada bit (?1? lógico = Entrada y ?0? lógico = Salida).
LATX: Escribiendo en cada bit la salida tendrá un nivel de Voltaje (?1? lógico = 5v | ?0? lógico = 0v).
PORTX: Este registro es de solo Lectura (5v =?1? lógico | 0v =?0? lógico).
 */



void InitPort(){
 //EEPROM_Init();
 OSCCON=0x72;
 USART_Init(9600);
 LATB=0;
 LATE=0;
 ADC_Init(5,0,4,4,1,0);
 //INTCONbits.RBIE   = 0; 
 //SPPCON=0;
 CS8_SetDigitalOutput();
 INC1_SetDigitalOutput();
 UPDW1_SetDigitalOutput();
 //INTCONbits.RBIE   = 0; 
 Calibration_Init();
// INTCONbits.RBIE   = 0; 

}
void Run_Protocol(){
    while(1){
    SENSOR_0=ADC_LecturaFiltro(10,0);
    SENSOR_1=ADC_LecturaFiltro(10,1);
    SENSOR_2=ADC_LecturaFiltro(10,4);
    SENSOR_3=ADC_LecturaFiltro(10,5);
    SENSOR_4=ADC_LecturaFiltro(10,6);
    SENSOR_5=ADC_LecturaFiltro(10,7);
    SENSOR_6=ADC_LecturaFiltro(10,8);
    SENSOR_7=ADC_LecturaFiltro(10,9);
    Concat_Value("s:",SENSOR_0,SENSOR_1,SENSOR_2,SENSOR_3,SENSOR_4,SENSOR_5,SENSOR_6,SENSOR_7);
    USART_TxS(result);
    USART_TxS("\n");
    //__delay_ms(5);
    }
}
void Checar_PCB(void){
  //__delay_ms(2000); 
  Pot_Set_Vref(40); 
  __delay_ms(100);
  //USART_TxS("hola");
  Pot_Set(0,70);
  //USART_TxS("listo 0"); 
  __delay_ms(200);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(1,70);
  //USART_TxS("listo 1"); 
  __delay_ms(200);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(2,70);
  //USART_TxS("listo 2"); 
  __delay_ms(200);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(3,70);
  //USART_TxS("listo 3"); 
  __delay_ms(200);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(4,70);
  //USART_TxS("listo 4"); 
  __delay_ms(100);
  //Run_Protocol();
 // __delay_ms(1000);
  
  Pot_Set(5,70);
  //USART_TxS("listo 5"); 
  __delay_ms(100);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(6,70);
  //USART_TxS("listo 6"); 
  __delay_ms(100);
  //Run_Protocol();
  //__delay_ms(1000);
  
  Pot_Set(7,70);
  //USART_TxS("listo 7"); 
  __delay_ms(100);
  //Run_Protocol();
  //__delay_ms(1000);
}

void main(void) {
  InitPort();
  Pot_Set_Vref(40);
 // USART_TxS("ola");
  __delay_ms(100);

  char code =USART_RxC();
  if (code=='c'){
     __delay_ms(100);
     Calibration_Run();
     __delay_ms(100);
     Run_Protocol();
    }else if(code=='r'){
     Run_Protocol();
      }else if(code=='s'){
        USART_TxS("s\n");

        Direction=0;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(10);

        //__delay_ms(1000);
        Direction=1;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);

        
        Direction=2;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        
        Direction=3;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        
        Direction=4;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        
        Direction=5;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        
        Direction=6;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        
        Direction=7;
        Direction=EEPROM_Decodificacion_Memoria(Direction);
        Lectura_Memoria(Direction);
        __delay_ms(100);
        //Run_Protocol();
      }
      __delay_ms(1000); 
  }
////RB4 NECESITA ESTAR CONECTADO A TIERRA, LO INTENTE CON OTROS PINES, ES EL QUE SE NECESITA PONER A TIERRA, 
