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

/*
                         Main application
 */
unsigned char xx=0, yy=0, zz=0;
unsigned char busra[]="Busra";
unsigned char sahin[]="Sahin";
unsigned char drc[]="16'C";
unsigned char tarih[]="09.01.2024";
unsigned char sali[]="SALI";
unsigned char a=0;
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    BT_GND_SetHigh();
    
    GLCD_init();
    while (1)
    {
       if(GLCD_on==0)
        {
            
            grafLCD_clear();
            //ekrani kullanma
            for(zz=0; zz<128; zz++)
            {
                goruntu[zz][0]=1;
                goruntu[zz][4]=8;
                goruntu[zz][7]=128;
                
                
            }    
            for(zz=0; zz<8; zz++) 
            {
                
                goruntu[0][zz]=255;
                goruntu[64][zz]=255;
                goruntu[127][zz]=255;
            
            }    
            //*******
            //kayan yazi,ekranibolme
            for(yy=0; yy<10; yy++)
            {
                
                grafLCD_show(1,2+(6*yy),1,5,(&(systemfont5x7[5*(tarih[yy]-32)])));
            
            }    
            for(yy=0; yy<4; yy++)
            {
             
                grafLCD_show(3,2+(6*yy),1,5,(&(systemfont5x7[5*(sali[yy]-32)])));
             
            } 
            //*********cumle
            for(yy=0; yy<5; yy++)
            {
                grafLCD_show(5,70+(6*yy),1,5,(&(systemfont5x7[5*(busra[yy]-32)]))); //busra degiskenini yazdi
                grafLCD_show(6,70+(6*yy),1,5,(&(systemfont5x7[5*(sahin[yy]-32)]))); //sahin degikenini yazd?rd?m
            }
            //********
            
            //******sayii
            cevir(a,BCD_disp,4,0);
            for(zz=0; zz<4; zz++)
                grafLCD_show(13,10+(6*zz),1,5,(&(systemfont5x7[80+(BCD_disp[zz]*5)])));
            
                    
            
            //***
            for(yy=0; yy<4; yy++)
            {
                 grafLCD_show(9,70+(6*yy),1,5,(&(systemfont5x7[5*(drc[yy]-32)])));
             
            }
            
            
            
            //*******animasyon****
             grafLCD_show(9,96,3,24,(&(donendaire[72*xx])));
             
             if( xx<2)
                 xx++;
             else
                 xx=0;
             //*********
            
//             grafLCD_show(2,30,3,24,(&(donendaire[72])));
//   
//             grafLCD_show(4,60,3,24,(&(donendaire[144])));
            // print_intk(1,10,1234,4,4);
            

            
            
            
          
            
            
            GLCD_on=1;
        }
        DELAY_milliseconds(200);
    }
    return 1; 
}
/**
 End of File
*/

