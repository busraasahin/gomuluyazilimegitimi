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



unsigned char xx=0, yy=0, zz=0;
unsigned char adsoyad[]="BUSRA SAHIN";



int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    BT_GND_SetHigh();
    
    lcd_init();
    
    unsigned char x=0;
    
    while(1)
    {
        if(LCD_rfrsh==0)
        {
            LCD_satir1=2;
            LCD_satir2=3;
            LCD_satir3=4;
            LCD_satir4=5;
            
            
//            for(x=0; x<20; x++)//ekran silme
//            {
//                LCD_dizi[0][x]=' ';
//                LCD_dizi[1][x]=' ';
//                LCD_dizi[2][x]=' ';
//                LCD_dizi[3][x]=' ';
//                
//            }   
            
//            cevir(1234,(&(LCD_dizi[0][0])),4,48); //karakter 
//            cevir(1234,(&(LCD_dizi[1][0])),4,48); //karakter 
//            cevir(2345,(&(LCD_dizi[2][0])),4,48); //karakter
//            cevir(1234,(&(LCD_dizi[3][0])),4,48); //karakter 
//            
//            LCD_dizi[0][15]='b'; LCD_dizi[0][16]='u'; LCD_dizi[0][17]='s';
//            LCD_dizi[0][18]='r'; LCD_dizi[0][19]='a'; 
            
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

    


