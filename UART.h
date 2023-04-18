#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
#define _XTAL_FREQ 8000000

void USART_Init(long BAUD);
void USART_TxC(char data);
char USART_RxC(void);
void USARTStr(char *Output, unsigned int size);
//void USART_TxSP(char Str[]);
void USART_RxS (char lenght, char* pointer );
char USART_TxS(char str[]);
char USART_TxSS(char str[], int length);
void USART_Overflow(void) ;
char Conexion_perdida=0;

#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */