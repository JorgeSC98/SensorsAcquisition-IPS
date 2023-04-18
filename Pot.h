#ifndef Pot_H
#define	Pot_H

#ifdef	__cplusplus
extern "C" {
#endif
#define _XTAL_FREQ 8000000
   
//C0 COMO INCREMENTO  
#define INC_TRIS                 TRISCbits.TRISC0
#define INC_LAT                  LATCbits.LATC0
#define INC_PORT                 PORTCbits.RC0
#define INC_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define INC_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define INC_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define INC_GetValue()           PORTCbits.RC0
#define INC_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define INC_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
    
    //C1 COMO UP/DOWN  
#define UPDW_TRIS                 TRISCbits.TRISC1 
#define UPDW_LAT                  LATCbits.LATC1
#define UPDW_PORT                 PORTCbits.RC1
#define UPDW_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define UPDW_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define UPDW_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define UPDW_GetValue()           PORTCbits.RC1
#define UPDW_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define UPDW_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
//D0 COMO SELECTOR SENSOR 0
#define CS0_LAT                  LATDbits.LATD0
#define CS0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define CS0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define CS0_GetValue()           PORTDbits.RD0
#define CS0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
//D1 COMO SELECTOR SENSOR 1
#define CS1_LAT                  LATDbits.LATD1
#define CS1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define CS1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define CS1_GetValue()           PORTDbits.RD1
#define CS1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
//D2 COMO SELECTOR SENSOR 2
#define CS2_LAT                  LATDbits.LATD2
#define CS2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define CS2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define CS2_GetValue()           PORTDbits.RD2
#define CS2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
//D3 COMO SELECTOR SENSOR 3
#define CS3_LAT                  LATDbits.LATD3
#define CS3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define CS3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define CS3_GetValue()           PORTDbits.RD3
#define CS3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)   
 //D6 COMO SELECTOR SENSOR 4
#define CS4_LAT                  LATDbits.LATD6
#define CS4_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define CS4_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define CS4_GetValue()           PORTDbits.RD6
#define CS4_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
 //D7 COMO SELECTOR SENSOR 5
#define CS5_LAT                  LATDbits.LATD7
#define CS5_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define CS5_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define CS5_GetValue()           PORTDbits.RD7
#define CS5_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
 ///D4 COMO SELECTOR SENSOR 6
#define CS6_LAT                  LATDbits.LATD4
#define CS6_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define CS6_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define CS6_GetValue()           PORTDbits.RD4
#define CS6_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)      
//D5 COMO SELECTOR SENSOR 7
#define CS7_LAT                  LATDbits.LATD5
#define CS7_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define CS7_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define CS7_GetValue()           PORTDbits.RD5
#define CS7_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)       
//B4 COMO INCREMENTO  VREF
    
#define INC1_TRIS                 TRISBbits.TRISB4
#define INC1_LAT                  LATBbits.LATB4
#define INC1_PORT                 PORTBbits.RB4
#define INC1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define INC1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define INC1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define INC1_GetValue()           PORTBbits.RB4
#define INC1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define INC1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)


//B6 COMO SELECTOR VREF
#define CS8_LAT                  LATBbits.LATB6
#define CS8_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define CS8_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define CS8_GetValue()           PORTBbits.RB6
#define CS8_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)  

 //B5 COMO UPDW  VREFTRI
#define UPDW1_TRIS                 TRISBbits.TRISB7
#define UPDW1_LAT                  LATBbits.LATB7
#define UPDW1_PORT                 PORTBbits.RB7
#define UPDW1_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define UPDW1_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define UPDW1_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define UPDW1_GetValue()           PORTBbits.RB7
#define UPDW1_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define UPDW1_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)   
    
    
void Pot_Init();
void Pot_Reset(uint8_t sensor);
void Pot_Increase(uint8_t sensor,uint8_t amount);
void Pot_Decrease(uint8_t sensor,uint8_t amount);
void Pot_Set(uint8_t sensor,uint8_t amount);
void Pot_Change(uint8_t sensor, bool direction, uint8_t amount);
void Pot_Reset_Vref();
void Pot_Increase_Vref(uint8_t amount);
void Pot_Decrease_Vref(uint8_t amount);
void Pot_Set_Vref(uint8_t amount);
void Pot_Change_Vref(bool direction, uint8_t amount);
void Pot_Selector(uint8_t sensor, bool status);
char Pot_Value_str[2];
#ifdef	__cplusplus
}
#endif

#endif