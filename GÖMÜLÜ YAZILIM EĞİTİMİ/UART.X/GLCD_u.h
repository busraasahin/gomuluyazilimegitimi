/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. 
//#include"extern_variables.h"
//#include "mcc_generated_files/system.h"
//#include "mcc_generated_files/../p33EP256MC206.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

void print_intk(unsigned char row,unsigned char column,unsigned int value,unsigned char uzunluk, unsigned char virgul);
void print_int(unsigned char row,unsigned char column,unsigned int value,unsigned char uzunluk, unsigned char virgul);
void grafLCD_clear(void);
void grafLCD_show(unsigned char satir, unsigned char sutun, unsigned char yukseklik, unsigned char genislik, const unsigned char* pointer);
void grafLCD_show_geri(unsigned char satir, unsigned char sutun, unsigned char yukseklik, unsigned char genislik, const unsigned char* pointer,unsigned char ters);
void grafLCD_show_t(unsigned char satir, unsigned char sutun, unsigned char yukseklik, unsigned char genislik, const unsigned char* pointer,unsigned char ters);
void grafLCD_yataycizgi(unsigned char basla, unsigned char bitir, unsigned char satir, unsigned char deger, unsigned char tur);
void grafLCD_fill_u (void);
void grafLCD_fill (unsigned char color);
void GLCD_init(void);
void glcd_write_data (unsigned int LCD_data,unsigned int chip);     
void glcd_write_com (unsigned int LCD_data,unsigned int chip); 
void delay_usg(unsigned int dly_us);
void print_char(unsigned char row,unsigned char column,unsigned char chr);
void print_cumle(unsigned char row,unsigned char column,const unsigned char *pointer,unsigned char width);

//#define GLCD_CS1  LATEbits.LATE13
//#define GLCD_CS2  LATEbits.LATE12
//#define GLCD_RST  LATEbits.LATE14
//#define GLCD_RW   LATEbits.LATE15
//#define GLCD_DI   LATAbits.LATA8
//#define GLCD_E    LATCbits.LATC3

extern unsigned char donendaire[];
extern unsigned char BCD_disp[];
extern unsigned char GLCD_on;
extern unsigned char goruntu[128][8];

extern unsigned int GLCD_x,GLCD_y;
extern const unsigned char harfler[];
extern const unsigned char rakam[];
extern const unsigned char sayilar[];
extern const unsigned char kolar_enerji[];
extern const unsigned char solarbold[],solarkol[],inverter[],server[],popt[];
extern const unsigned char bos[];
extern unsigned char systemfont5x7[];

extern const unsigned char porte[];
extern const unsigned char tristor_1[];
extern const unsigned char P_ler[];
extern const unsigned char mesaj1[],mesaj2[],mesaj3[],mesaj4[],mesaj5[];

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    

   

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

