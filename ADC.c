/*
 * File:   ADC.c
 * Author: saenz
 *
 * Created on 17 de febrero de 2022, 01:11 PM
 */

//1/4Mhz= .250us
//4Tosc= 1us=TAD
//2.45us<xTAD  
//X=4 4us

#include <xc.h>
#include "ADC.h"
#include <pic18f4550.h>
#include <string.h>
//1/8Mhz= .125us
//8Tosc= 1us=TAD
//2.45us<xTAD  
//X=4 4us



/*void ADC_Lectura(void) {
    ADCON0bits.GO_DONE = 1; //Inicia la COnversió AD.
    while (ADCON0bits.GO_DONE);
    bites_menosS = ADRESL; //Guardas los 8 bits menos significativos de la lectura
    bites_masS = ADRESH; //Guardas los 2 bits mas significativos de la lectura
}*/
void ADC_Init(uint8_t entradas_analogicas, uint8_t Vref, uint8_t Clock, uint8_t ADQT, uint8_t justificacion, uint8_t estado) 
{
    ADCON1bits.PCFG=entradas_analogicas;    // ADCON1bits.PCFG 
                                            //      PCFG AN12  AN11  AN10  AN9  AN8  AN7  AN6  AN5  AN4  AN3  AN2  AN1  AN0
                                            // 0    0000 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 1    0001 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 2    0010 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 3    0011 D     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 4    0100 D     D     A     A    A    A    A    A    A    A    A    A    A 
                                            // 5    0101 D     D     D     A    A    A    A    A    A    A    A    A    A 
                                            // 6    0110 D     D     D     D    A    A    A    A    A    A    A    A    A 
                                            // 7    0111 D     D     D     D    D    A    A    A    A    A    A    A    A 
                                            // 8    1000 D     D     D     D    D    D    A    A    A    A    A    A    A 
                                            // 9    1001 D     D     D     D    D    D    D    A    A    A    A    A    A     
                                            //10    1010 D     D     D     D    D    D    D    D    A    A    A    A    A 
                                            //11    1011 D     D     D     D    D    D    D    D    D    A    A    A    A 
                                            //12    1100 D     D     D     D    D    D    D    D    D    D    A    A    A 
                                            //13    1101 D     D     D     D    D    D    D    D    D    D    D    A    A 
                                            //14    1110 D     D     D     D    D    D    D    D    D    D    D    D    A 
                                            //15    1111 D     D     D     D    D    D    D    D    D    D    D    D    D 
    
    ADCON1bits.VCFG=Vref;                   // ADCON1bits.VCFG
                                            // Vref     VCFG1   VCFG0   
                                            // 3        1       1       Vref- (AN2)     Vref+ (AN3)
                                            // 0        0       0       Vss             Vdd 
    
    ADCON2bits.ADCS=Clock;                  // ADCON2bits.ADCS >> TAD debe ser mayor a 0.7us
                                            // Clock  ADCS     TAD
                                            // 0      000      2*Tosc
                                            // 1      001      8*Tosc
                                            // 2      010      32*Tosc
                                            // 3      011      Frc
                                            // 4      100      4*Tosc
                                            // 5      101      16*Tosc
                                            // 6      110      64*Tosc
                                            // 7      111      Frc
    
    ADCON2bits.ACQT=ADQT;                   // ADCON2bits.ACQT >> El tiempo de adquisición debe ser mayor a 2.45us
                                            // ADQT   ACQT      Tiempo de adquisición
                                            // 0      000       0*TAD
                                            // 1      001       2*TAD
                                            // 2      010       4*TAD
                                            // 3      011       6*TAD
                                            // 4      100       8*TAD
                                            // 5      101       12*TAD
                                            // 6      110       16*TAD
                                            // 7      111       20*TAD
    
    ADCON2bits.ADFM=justificacion;          // ADFM
                                            // 0        Izquierda
                                            // 1        Derecha
    
    ADCON0bits.ADON=estado;                 // ADON
                                            // 0        Deshabilitado
                                            // 1        Habilitado
   }

int Leer_Canal_ADC(uint8_t Canal)
{
    int ADC;                       // Variable que retornará el valor de los registros ADRESH y ADRESL.
    ADCON0bits.CHS=Canal;               // ADCON0bitsCHS
                                        // Canal 
                                        // 0        0000 = Channel 0 (AN0)
                                        // 1        0001 = Channel 1 (AN1)
                                        // 2        0010 = Channel 2 (AN2)
                                        // 3        0011 = Channel 3 (AN3)
                                        // 4        0100 = Channel 4 (AN4)
                                        // 5        0101 = Channel 5 (AN5)(1,2)
                                        // 6        0110 = Channel 6 (AN6)(1,2)
                                        // 7        0111 = Channel 7 (AN7)(1,2)
                                        // 8        1000 = Channel 8 (AN8)
                                        // 9        1001 = Channel 9 (AN9)
                                        //10        1010 = Channel 10 (AN10)
                                        //11        1011 = Channel 11 (AN11)
                                        //12        1100 = Channel 12 (AN12)
    
    
    ADCON0bits.ADON=1;
    ADCON0bits.GO_DONE=1;               // Inicializamos la conversión 
    while(ADCON0bits.GO_DONE==1);       // Esperamos ha que termine la conversión.
    ADCON0bits.ADON=0;
    ADC=ADRESH;                         // Cargamos ADC con los 8 bits del registro ADRESH
    ADC=ADC<<8;                         // Desplazamos 8 bits a la izquierda del registro ADC.
    ADC|=ADRESL;                        // Realizamos una operación lógica OR entre ADC y ADRESL el resultado se almacena en ADC
    //__delay_ms(4);
    return ADC;
}

/*void ADC_Init(void) {
    TRISAbits.RA0 = 1; //RA0 COMO ENTRADA
    ADCON1bits.PCFG = 0b1110; //  Configura el Puerto como Entrada Analógica.
    ADCON1bits.VCFG = 0b00; //  Selecciona Voltajes de Referencia (5v-0v).
    ADCON0 = 0; //  Selecciona el Canal Analógico.
    ADCON2bits.ACQT = 4; //TADQ =X DE 8
    ADCON2bits.ADCS = 4; //4TOSC
    ADCON2bits.ADFM = 1; //  Justificación derecha (modo-10bits).
    ADCON0bits.ADON = 1; //  Habilita el Módulo AD.
}*/
int ADC_LecturaFiltro(int n, uint8_t Canal ) {
    int lectura = 0;
    Suma = 0;
    for (int i = 0; i < n; i++) {
        lectura=Leer_Canal_ADC(Canal);
        //lectura = ADC_InsertBits(bites_menosS, bites_masS);
        Suma = Suma + lectura;
      // __delay_ms(4);
    }
    return (Suma / n);
}
int ADC_Lectura_Sensores(int n) {
    int Lectura_0 = 0;
    int Lectura_1 = 0;
    int valor = 0;
    Suma = 0;
    for (int i = 0; i < n; i++) {
        valor=Leer_Canal_ADC(0);
        Lectura_0 = Lectura_0 + valor;
       //__delay_ms(4);
    }
    Lectura_0 = Lectura_0 / n;
    valor=0;
    for (int i = 0; i < n; i++) {
        valor=Leer_Canal_ADC(1);
        Lectura_1 = Lectura_1 + valor;
       //__delay_ms(4);
    }
    Lectura_1 = Lectura_1 / n;
    return Lectura_0,Lectura_1;
}

int ADC_InsertBits(char Bmenos, char Bmas) {
    Bmas &= ~(0xC); //PONE EN 0 LOS 6 BITS MAS SIGNIFICATIVOS 
    Lectura = Bmenos; // AGREGA LOS BITS MENOS SIGNIFICATIVOS A LA VARIABLE
    Lectura &= ~(0xFFFFFF << 8); // LIMPIA LOS 6 BYTES MAS SIGNIFICATIVOS PARA POSTERIOR ESCRITURA
    Lectura |= ((Bmas & 0x3) << 8); //Agrega los 2 bits mas significativos
    return Lectura;
}
void strreverse(char* begin, char* end)
{  
    char aux;  
    while(end>begin)   
        aux=*end, *end--=*begin, *begin++=aux; 
}
void changeInt(int value, char *str)
{
    char* wstr=str;
    int sign;  
    div_t res;
   
    if ((sign=value) < 0) value = -value;
   
    do {   
      *wstr++ = (value%10)+'0';
    }while(value=value/10);
   
    if(sign<0) *wstr++='-';
    *wstr='\0';

    strreverse(str,wstr-1);
}
void Concat_Value(char id[2], int Lectura0,int Lectura1, int Lectura2,int Lectura3,int Lectura4, int Lectura5, int Lectura6, int Lectura7){
 strcpy( result,id);
 changeInt(Lectura0,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura1,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura2,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura3,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura4,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura5,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura6,cadena);
 strcat( result,cadena );
 strcat( result,"," );
 changeInt(Lectura7,cadena);
 strcat( result,cadena );
 //strcat( result,",200,300,400" );
}
