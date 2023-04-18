/*
 * File:   Pot.c
 * Author: saenz
 *
 * Created on 23 de julio de 2022, 11:02 AM
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
#include "Pot.h"
void Pot_Init() {
    
    INC_SetDigitalOutput();//Declarar INC como salida digital
    __delay_ms(10);
    UPDW_SetDigitalOutput(); //Declarar UPDW como salida digital
    __delay_ms(100);
    //USART_TxS("ANTES"); 
    INC1_SetDigitalOutput();//Declarar INC como salida digital
    __delay_ms(100);
   // USART_TxS("DESPUES"); 
    UPDW1_SetDigitalOutput(); //Declarar UPDW como salida digital
     //Declarar selectores como salidas digitales
     __delay_ms(100);
    CS0_SetDigitalOutput();
    __delay_ms(10);
    CS1_SetDigitalOutput();
    __delay_ms(10);
    CS2_SetDigitalOutput();
    __delay_ms(10);
    CS3_SetDigitalOutput();
    __delay_ms(10);
    CS4_SetDigitalOutput();
    __delay_ms(10);
    CS5_SetDigitalOutput();
    __delay_ms(10);
    CS6_SetDigitalOutput();
    __delay_ms(10);
    CS7_SetDigitalOutput();
    __delay_ms(10);
    //CS8_SetDigitalOutput();
     __delay_ms(100);
    //Desactivar selectores
    CS0_SetHigh();
    __delay_ms(10);
    CS1_SetHigh();
    __delay_ms(10);
    CS2_SetHigh();
    __delay_ms(10);
    CS3_SetHigh();
    __delay_ms(10);
    CS4_SetHigh();
    __delay_ms(10);
    CS5_SetHigh();
    __delay_ms(10);
    CS6_SetHigh();
    __delay_ms(10);
    CS7_SetHigh();
    CS8_SetHigh();
    
}
void Pot_Reset(uint8_t sensor){
    Pot_Decrease(sensor,99);
}
void Pot_Increase(uint8_t sensor,uint8_t amount){
    Pot_Change(sensor,1, amount);
}
void Pot_Decrease(uint8_t sensor,uint8_t amount){
    Pot_Change(sensor,0, amount);
}
void Pot_Set(uint8_t sensor,uint8_t amount){
   Pot_Reset(sensor);
   Pot_Increase(sensor,amount);
}
void Pot_Change(uint8_t sensor,bool direction, uint8_t amount){
    UPDW_LAT = direction;
    INC_SetHigh();
    Pot_Selector(sensor,0);
    for (uint8_t i=0; i<amount; i++) {
        INC_SetLow();
        __delay_ms(5);
        INC_SetHigh();
                
    }
    Pot_Selector(sensor,1); 
}
void Pot_Selector(uint8_t sensor, bool status){
    switch (sensor){
        case 0:
            CS0_LAT=status;
            __delay_ms(5);
            break;
        case 1:
            CS1_LAT=status;
            __delay_ms(5);
            break;
        case 2:
            CS2_LAT=status;
            __delay_ms(5);
            break;
        case 3:
            CS3_LAT=status;
            __delay_ms(5);
            break;
        case 4:
            CS4_LAT=status;
            __delay_ms(5);
            break;
        case 5:
            CS5_LAT=status;
            __delay_ms(5);
            break;
        case 6:
            CS6_LAT=status;
            __delay_ms(5);
            break;
        case 7:
            CS7_LAT=status;
            __delay_ms(5);
            break;
        case 8:
            CS8_LAT=status;
            __delay_ms(5);
            break;    
    }
}
void Pot_Increase_Vref(uint8_t amount){
    Pot_Change_Vref(1, amount);
}
void Pot_Decrease_Vref(uint8_t amount){
    Pot_Change_Vref(0, amount);
}
void Pot_Reset_Vref(){
    Pot_Decrease_Vref(99);
}
void Pot_Change_Vref(bool direction, uint8_t amount){
    UPDW1_LAT = direction;
    INC1_SetHigh();
    Pot_Selector(8,0);
    for (uint8_t i=0; i<amount; i++) {
        INC1_SetLow();
        __delay_ms(5);
        INC1_SetHigh();
                
    }
    Pot_Selector(8,1); 
}
void Pot_Set_Vref(uint8_t amount){
   Pot_Reset_Vref();
   Pot_Increase_Vref(amount);
}