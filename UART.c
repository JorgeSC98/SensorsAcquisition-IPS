/*
 * File:   UART.c
 * Author: saenz
 *
 * Created on 17 de febrero de 2022, 01:12 PM
 */


#include <xc.h>
#include <string.h>
#include <stdlib.h>
#include "conf.h"
#include "UART.h"
void USART_Init(long BAUD){  
    TRISCbits.RC6 = 0;      
    TRISCbits.RC7 = 1;      
    

    SPBRG = (unsigned char)(((8000000/BAUD)/64)-1);//define el valor del baudaje

    TXSTAbits.BRGH = 0;     
    TXSTAbits.SYNC = 0;     
    RCSTAbits.SPEN = 1;     
    
    TXSTAbits.TX9 = 0;   
    TXSTAbits.TXEN = 1;     
    
    
    RCSTAbits.RC9 = 0;    
    RCSTAbits.CREN = 1;     
}

void USART_TxC(char data){
    while(!PIR1bits.TXIF);
    TXREG = data;
}

char USART_RxC(void){
    USART_Overflow();
    while(!PIR1bits.RCIF);
    return RCREG; 
}
char USART_TxS(char str[]){
    int length=strlen(str);
    for (int i=0;i<length;i++){
    while(!PIR1bits.TXIF);
    TXREG = str[i];
    }
}
char USART_TxSS(char str[], int length){
    for (int i=0;i<length;i++){
    while(!PIR1bits.TXIF);
    TXREG = str[i];
    }
}

/*
void USART_TxSP(char Str[]){
    int Strindex = 0;
    while(Str[Strindex] != 0);
    USART_TxC(Str[Strindex]);
    Strindex++;
}*/

void USART_RxS (char length, char* pointer ){//funcion pa leer string
    USART_Overflow();
    long count=0;
    Conexion_perdida=0;
    for (int i = 0; i < (length); i++) 
        {
            while (!RCIF){
                count++;
                if (count>2500000){
                    Conexion_perdida=1;
                    count=0;
                    return;
                }
            }
            pointer[i] = RCREG;
        }
}
void USART_Overflow(void) {
    char temp;
    if(OERR) {//¿hubo desborde?
    
        do
        {
            temp = RCREG;//limpia pila
            temp = RCREG;//limpia pila
            temp = RCREG;//limpia pila
            CREN = 0;//deshabilita la recepcion
            CREN = 1;//habilita la recepcion

        } while(OERR);
         USART_TxS("E4\n");
    }

    if(FERR)
    {
        temp = RCREG;
        TXEN = 0;
        TXEN = 1;
    }
}