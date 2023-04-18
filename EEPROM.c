/*
 * File:   EEPROM.c
 * Author: saenz
 *
 * Created on 2 de noviembre de 2022, 07:30 PM
 */


#include <xc.h>
#include "EEPROM.h"
#include "UART.h"
/*
void EEPROM_Init(){
    EECON1bits.CFGS=0;
    EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
    EECON1bits.WREN=1;//PERMITIR WRITE OPERATION
}*/
char EEPROM_Rx(char direccion){
    EEADR=direccion;//DIRECCION A LEER
    EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
      EECON1bits.CFGS=0;// //DATA EEPROM
      EECON1bits.RD=1;// HABILITAR LECTURA
      data=EEDATA;//LEER DATO Y GUARDARLO EN VARIABLE
      return data;
}
void EEPROM_Tx(char direccion, char dato){
    EEADR=direccion;//DIRECCION A ESCRIBIR
    EEDATA=dato;//DATO A GUARDAR
     EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
      EECON1bits.CFGS=0;// //DATA EEPROM
      EECON1bits.WREN=1;// ENABLE WRITES
      INTCONbits.GIE=0;//DISABLE INTERRUPTS
      //PASOS NECESARIOS POR LA DATASHEET PARA ESCRIBIR
      EECON2=0x55;
      EECON2=0x0AA;
      EECON1bits.WR=1;//ENABLE WRITE
      INTCONbits.GIE=1;//ENABLE INTERRUPT
      while(!PIR2bits.EEIF);
      PIR2bits.EEIF=0;
      EECON1bits.WREN=0 ;// DISABLE WRITES
      //APAGAR BANDERA EEIF
}
int Lectura_Memoria(char direccion) {
    char potenciometro[2];
    char direccionX;
    for (int i = 0; i < 2; i++) {
        direccionX = direccion + i;
        potenciometro[i] = EEPROM_Rx(direccionX); //Guardar datos de le EEPROM en string
    }
    //USART_TxSS(potenciometro,2);
    //USART_TxS("\n");
    char potenciometro_value[2];
    char counter=0;
     for (int i = 0; i < 2; i++) {
        counter = counter + i;
        potenciometro_value[i]=potenciometro[i];
    }
    Calibration_value=atoi(potenciometro_value);
    return Calibration_value;
}
void Escritura_Memoria(char direccion, char string_pot[]) {
    char direccionFinal;
    for (int i = 0; i < 2; i++) {
        direccionFinal = direccion + i;
        EEPROM_Tx(direccionFinal, string_pot[i]);
    }
}
char EEPROM_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case 0:
            direccion = 0x00;
            //USART_TxS("C0\n", sizeof ("C0\n") - 1);
            break;
        case 1:
            direccion = 0x10;
            //USART_TxS("C1\n", sizeof ("C1\n") - 1);
            break;
        case 2:
            direccion = 0x20;
            //USART_TxS("C2\n", sizeof ("C2\n") - 1);
            break;
        case 3:
            direccion = 0x30;
            //USART_TxS("C3\n", sizeof ("C3\n") - 1);
            break;
        case 4:
            direccion = 0x40;
            //USART_TxS("C4\n", sizeof ("C4\n") - 1);
            break;
        case 5:
            direccion = 0x50;
            //USART_TxS("C5\n", sizeof ("C5\n") - 1);
            break;
        case 6:
            direccion = 0x60;
            //USART_TxS("C6\n", sizeof ("C6\n") - 1);
            break;
        case 7:
            direccion = 0x70;
            //USART_TxS("C7\n", sizeof ("C7\n") - 1);
            break;
        case 8:
            direccion = 0x80;
            //USART_TxS("C8\n", sizeof ("C8\n") - 1);
            break;
        case '9':
            direccion = 0x90;
            //USART_TxS("C9\n", sizeof ("C9\n") - 1);
            break;
        case 'A':
            direccion = 0xA0;
            //USART_TxS("CA\n", sizeof ("CA\n") - 1);
            break;
        case 'B':
            direccion = 0xB0;
            //USART_TxS("CB\n", sizeof ("CB\n") - 1);
            break;
        case 'C':
            direccion = 0xC0;
            //USART_TxS("CC\n", sizeof ("CC\n") - 1);
            break;
        case 'D':
            direccion = 0xD0;
            //USART_TxS("CD\n", sizeof ("CDn") - 1);
            break;
        case 'E':
            direccion = 0xE0;
            //USART_TxS("CE\n", sizeof ("CE\n") - 1);
            break;
        case 'F':
            direccion = 0xF0;
            //USART_TxS("CF\n", sizeof ("CF\n") - 1);
            break;
    }
    return direccion;
}
