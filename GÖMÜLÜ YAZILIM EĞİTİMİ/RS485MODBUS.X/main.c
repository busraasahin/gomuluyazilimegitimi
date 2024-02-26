/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33EP64GS506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/delay.h"

#include "cevir.h"
#include "GLCD_u.h"
#include "LCDu.h"
#include "mcc_generated_files/tmr1.h"

#include "mcc_generated_files/uart1.h"

#include "comm_1.h"

unsigned char xx=0, yy=0, zz=0;
unsigned char adsoyad[]="BUSRA SAHIN";

unsigned char rxdata=0;
extern unsigned char rx_buffer[];
extern unsigned char tx_buffer[];

extern unsigned char paket_geldi;
extern unsigned char gidecek_veri;

extern union dataform_1 modbus_degiskenleri[20];
extern volatile unsigned char *modbus_pointer;

unsigned char crch_rx, crcl_rx=0;

int main(void)
{
    // initialize the device
         SYSTEM_Initialize();
         BT_GND_SetHigh();
         
         rs485_dir_SetLow(); //her zaman dinleme modunda basla
         
          
        //modbus_degiskenleri[1].word[0]=380; //1 7c
    
//         modbus_degiskenleri[0].word[0]=380;
//
//         modbus_degiskenleri[0].word[1]=221;
//     
//         modbus_degiskenleri[1].word[0]=230;  
//       
//         modbus_degiskenleri[1].word[1]=231;  

        
//       modbus_degiskenleri[0].bytes[0]=220;
//       modbus_degiskenleri[0].bytes[1]=221;
//       modbus_degiskenleri[0].bytes[2]=219;
//       modbus_degiskenleri[0].bytes[3]=129;
//       
//       modbus_degiskenleri[1].bytes[0]=125;
//       modbus_degiskenleri[1].bytes[1]=13;
//       modbus_degiskenleri[1].bytes[2]=155;
//       modbus_degiskenleri[1].bytes[3]=225;
    
    
    
    lcd_init();
    
    unsigned char x=0;
    
            LCD_satir1=0;
            LCD_satir2=0;
            LCD_satir3=0;
            LCD_satir4=0;
            
            
            for(x=0; x<20; x++)//ekran silme
            {
                LCD_dizi[0][x]=' ';
                LCD_dizi[1][x]=' ';
                LCD_dizi[2][x]=' ';
                LCD_dizi[3][x]=' ';
                
                tx_buffer[x]=0;
                
            }  
    
//    rxdata=UART1_Read();
    
//        modbus_degiskenleri[0].dword=87654321;
//        modbus_degiskenleri[1].dword=12345678;
//         modbus_degiskenleri[0].word[0]=32765;
//         modbus_degiskenleri[0].word[1]=200;
            
       
       
       
//       modbus_degiskenleri[0].bits.bit0=1;
//       modbus_degiskenleri[0].bits.bit25=1;
       
    while(1)
    {
        if(LCD_rfrsh==0)
        {
            
            
            
            cevir(modbus_degiskenleri[0].word[0],(&(LCD_dizi[0][0])),5,48);
            cevir(modbus_degiskenleri[0].word[1],(&(LCD_dizi[1][0])),5,48);
            
            cevir(modbus_degiskenleri[3].word[0],(&(LCD_dizi[0][6])),5,48);
            cevir(modbus_degiskenleri[3].word[1],(&(LCD_dizi[1][6])),5,48);
            
            cevir(modbus_degiskenleri[5].word[0],(&(LCD_dizi[0][12])),5,48);
            cevir(modbus_degiskenleri[5].word[1],(&(LCD_dizi[1][12])),5,48);
            
//            cevir((modbus_degiskenleri[1].bytes[0]),(&(LCD_dizi[2][0])),3,48);
//            cevir((modbus_degiskenleri[1].bytes[1]),(&(LCD_dizi[2][5])),3,48);
//            cevir((modbus_degiskenleri[1].bytes[2]),(&(LCD_dizi[2][10])),3,48);
//            cevir((modbus_degiskenleri[1].bytes[3]),(&(LCD_dizi[2][15])),3,48);
//            
//            cevir(modbus_pointer[0],(&(LCD_dizi[3][0])),3,48);
//            cevir(modbus_pointer[1],(&(LCD_dizi[3][5])),3,48);
//            cevir(modbus_pointer[2],(&(LCD_dizi[3][10])),3,48);
//            cevir(modbus_pointer[3],(&(LCD_dizi[3][15])),3,48);
//            cevir(modbus_degiskenleri[0].word[0],(&(LCD_dizi[1][3])),5,48);
//            cevir(modbus_degiskenleri[0].word[1],(&(LCD_dizi[2][3])),5,48);
//            
//            cevir(modbus_degiskenleri[0].bytes[0],(&(LCD_dizi[3][0])),3,48);
//            cevir(modbus_degiskenleri[0].bytes[1],(&(LCD_dizi[3][5])),3,48);
//            cevir(modbus_degiskenleri[0].bytes[2],(&(LCD_dizi[3][10])),3,48);
//            cevir(modbus_degiskenleri[0].bytes[3],(&(LCD_dizi[3][15])),3,48);
            
//            if(modbus_goster)
//            {
//                
//                modbus_goster=0;
//                
//                cevir(rx_buffer[0],(&(LCD_dizi[0][0])),3,48);
//                cevir(rx_buffer[1],(&(LCD_dizi[0][4])),3,48);
//                cevir(rx_buffer[2],(&(LCD_dizi[0][8])),3,48);
//                cevir(rx_buffer[3],(&(LCD_dizi[0][12])),3,48);
//                cevir(rx_buffer[4],(&(LCD_dizi[0][16])),3,48);
//                cevir(rx_buffer[5],(&(LCD_dizi[1][0])),3,48);
//                cevir(rx_buffer[6],(&(LCD_dizi[1][4])),3,48);
//                cevir(rx_buffer[7],(&(LCD_dizi[1][8])),3,48);
//                cevir(crcl_rx,(&(LCD_dizi[1][12])),3,48);
//                cevir(crch_rx,(&(LCD_dizi[1][16])),3,48);
//                
//                
//            
//                
////                for(x=0; x<20; x++)
////                LCD_dizi[3][x]=rx_buffer[x];
//                
////                switch(rx_buffer[0])
////                {
////                    case 'A':
////                    {
////                        tx_buffer[0]='A';
////                        tx_buffer[1]='L';
////                        tx_buffer[2]='I';
////                       
////                        gidecek_veri=5;
////                    }
////                    break;    
////                    
////                    case 'B':
////                    {
////                        tx_buffer[0]='B';
////                        tx_buffer[1]='A';
////                        tx_buffer[2]='B';
////                        tx_buffer[3]='A';
////                        
////                        gidecek_veri=11;
////                    }
////                    break; 
////                }        
//              
//            }
            if(modbus_cevap)
            {
                modbus_cevap=0;
                cevir(tx_buffer[0],(&(LCD_dizi[2][0])),3,48);
                cevir(tx_buffer[1],(&(LCD_dizi[2][4])),3,48);
                cevir(tx_buffer[2],(&(LCD_dizi[2][8])),3,48);
                cevir(tx_buffer[3],(&(LCD_dizi[2][12])),3,48);
                cevir(tx_buffer[4],(&(LCD_dizi[2][16])),3,48);
                cevir(tx_buffer[5],(&(LCD_dizi[3][0])),3,48);
                cevir(tx_buffer[6],(&(LCD_dizi[3][4])),3,48);
                cevir(tx_buffer[7],(&(LCD_dizi[3][8])),3,48);
                cevir(tx_buffer[8],(&(LCD_dizi[3][12])),3,48);
                cevir(tx_buffer[9],(&(LCD_dizi[3][16])),3,48);
               
                
            }    
            
//            cevir(1234,(&(LCD_dizi[0][0])),4,48); //karakter 
//            cevir(1234,(&(LCD_dizi[1][0])),4,48); //karakter 
//            cevir(2345,(&(LCD_dizi[2][0])),4,48); //karakter
//            cevir(1234,(&(LCD_dizi[3][0])),4,48); //karakter 
//            
            
            //cevir(rxdata,(&(LCD_dizi[3][12])),3,48);
            
            
            LCD_rfrsh=1;
        }    
    
        DELAY_milliseconds(200);
    }    
    
    
    
    lcd_send_byte(0, LCD_satir1_adr);
    for(zz=0; zz<20; zz++)
         lcd_send_byte(1,' ');
    lcd_send_byte(0, LCD_satir2_adr);
    for(zz=0; zz<20; zz++)
         lcd_send_byte(1,' ');
    lcd_send_byte(0, LCD_satir3_adr);
    for(zz=0; zz<20; zz++)
         lcd_send_byte(1,' ');
    lcd_send_byte(0, LCD_satir4_adr);
    for(zz=0; zz<20; zz++)
         lcd_send_byte(1,' ');
    
    lcd_send_byte(0, LCD_satir2_adr+yy);
    
        
    LCD_cumleyaz(1,1,11,adsoyad);
    LCD_sayi_yaz(2,2,4,2000);
    
    
    while(1);
    
    return 1; 
}

    


