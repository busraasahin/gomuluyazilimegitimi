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
/*
                         Main application
 */
//fonksiyon prototipi
void ayir(unsigned int sayi);
void rakamyaz(unsigned char rakam);
void sifir(void);
void bir(void);
void iki(void);
void uc(void);
void dort(void);
void bes(void);
void alti(void);
void yedi(void);
void sekiz(void);
void dokuz(void);

unsigned long bekle=0;
unsigned char a=0, b=0, c=0, d=0;
unsigned int sayim=0;




int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    BT_GND_SetHigh();
    
    
    
//    LED4_SetDigitalInput();
//    LED5_SetDigitalInput();
//    LED6_SetDigitalInput();
//    LED7_SetDigitalInput();
//    LED8_SetDigitalInput();
    
//    BT_GND_SetLow();
    
    while (1)
    {
       // for(bekle=0; bekle<500000;bekle++);
     
        if(sayim>9999)
        sayim=0;
    }    
  
    return 1; 
}
void ayir(unsigned int sayi)
{
    a=0; b=0; c=0; d=0;
    if(sayi<10000)
        {
            while(sayi>=1000)
            {
                sayi=sayi-1000;
                a++;
            }
           while(sayi>=100)
            {
                sayi=sayi-100;
                b++;
            }
            while(sayi>=10)
            {
                sayi=sayi-10;
                c++;
            }
            d=sayi;
        }
       
}
void rakamyaz(unsigned char rakam)
{
    switch(rakam) 
    {
        case 0: sifir();   break;
        case 1: bir();     break;
        case 2: iki();     break;
        case 3: uc();      break;
        case 4: dort();    break;
        case 5: bes();     break;
        case 6: alti();    break;
        case 7: yedi();    break;
        case 8: sekiz();   break;
        case 9: dokuz();   break;
    }
}
void sifir(void)
    {
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetLow();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetHigh();
    LED8_SetHigh();  
    }
void bir(void)
{
    LED1_SetHigh();
    LED2_SetLow();
    LED3_SetLow();
    LED4_SetLow();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetLow();  
}
void iki(void)
{
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetLow();
    LED4_SetHigh();
    LED5_SetLow();
    LED6_SetLow();
    LED7_SetHigh();
    LED8_SetHigh();  
}
void uc(void)
{
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetLow();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetHigh();  
}
void dort(void)
{
    LED1_SetHigh();
    LED2_SetLow();
    LED3_SetHigh();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetLow();  
}
void bes(void)
{
    LED1_SetLow();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetHigh();  
}
void alti(void)
{
    LED1_SetLow();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetHigh();
    LED8_SetHigh();  
}
void yedi(void)
{
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetLow();
    LED4_SetLow();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetLow();  
}
void sekiz(void)
{
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetHigh();
    LED8_SetHigh();  
}
void dokuz(void)
{
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetHigh();
    LED5_SetHigh();
    LED6_SetLow();
    LED7_SetLow();
    LED8_SetHigh();  
}
/**
 End of File
*/

