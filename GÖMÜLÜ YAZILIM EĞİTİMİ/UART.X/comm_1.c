
#include  <xc.h>
#include "mcc_generated_files/uart1.h"
#include "comm_1.h"

unsigned char com_peryot=0;
unsigned char tx_buffer[]="Busra SAHIN";
unsigned char tx_indis=0;
unsigned char gidecek_veri=0;

unsigned char rx_buffer[20];
unsigned char rx_indis=0;

unsigned char com1_timeout=0;
unsigned char paket_geldi=0;

void receive (void)
{
    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }    
        
    if(U1STAbits.URXDA == 1) //gelen veri hazir
    {
         com1_timeout=0;
         
         rx_buffer[rx_indis]=U1RXREG;
         
         if(rx_indis<19)
         rx_indis++;
                 
    } 

}

void send (void)
{
    if(gidecek_veri>0)
        {    
            
        if(U1STAbits.UTXBF == 0) //transmit buffer bosalmissa
           {
           U1TXREG=tx_buffer[tx_indis];
           if (tx_indis<11)
               tx_indis++;
           else
               tx_indis=0;
               gidecek_veri--;
           }
        }
        else
        {
            tx_indis=0;
        } 
   

}
void haberles (void)
{
     receive();
     
     if(com_peryot<20) //2msde bir gonder
        com_peryot++;
    else 
    {   
        com_peryot=0;
        if(com1_timeout<10) //20msn'de timeout
        com1_timeout++;
        else
        { 
            if(rx_indis>0)
            paket_geldi=1;
            rx_indis=0;
        } 
        
        send();
    }
    
}