#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/delay.h"

#include "LCD_msg.h" //baska hicbir yerde bu dosyayi ekleme
#include "LCDu.h"
#include "GLCD_u.h"
#include "cevir.h"

///********DISARIDAN ERISMEMIZ GEREKEN DEGISKENLER*****
unsigned char LCD_rfrsh=0;
unsigned char LCD_dizi[LCD_satir][LCD_sutun];
unsigned char LCD_satirx[LCD_satir];
///////////////************

///*************DISARIDAN ERISILMEMESI GEREKEN DEGISKENLER****
unsigned char LCD_data=0, LCD_data_h=0, LCD_data_l=0;
unsigned char LCD_i=0, LCD_j=0, LCD_don=0;
///*****************************************************



void LCD(void) //state machine 100usn de 1 kez cagrilmak uzere
{
    LCD_i++;
    
    switch(LCD_i)
    {
        case 1:
        {
            LCD_EN_SetLow(); 
            GLCD_RW_SetLow();
            GLCD_DI_SetLow();

        }
        break;

        case 2:
        {
            LED5_SetLow(); //1000 
            LED6_SetLow();
            LED7_SetLow();
            LED8_SetHigh();

        }
        break;

        case 3:
        {
            LCD_EN_SetHigh();

        }
        break;
        case 4:
        {
            LCD_EN_SetLow();

        }
        break;
        case 5:
        {
            LED5_SetLow(); //1000 
            LED6_SetLow();
            LED7_SetLow();
            LED8_SetLow();

        }
        break;

        case 6:
        {
            LCD_EN_SetHigh();

        }
        break;
        case 7:
        {
            LCD_EN_SetLow();

        }
        break;
        
        case 40:
        {
            GLCD_DI_SetHigh();
           
            
            if(LCD_satir1)
            LCD_i++;
            
            LCD_j=0;
        }
        break;

        case 41: //RAM'den veri gonderme dongusu
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_dizi[0][LCD_j];

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_i=yaz;
                LCD_don=40;
            }   
            else
            {    
                LCD_j=0;
                LCD_i++;
                       
            }
        }
        break;
        
        case 42: //ROM' dan veri gonderme dongusu
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_mesajlari[LCD_satir1][LCD_j];

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;
                
                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            }   
            else
                LCD_j=0;

        }
        break;
        
        case 43:
        {
            if(LCD_satir3)
            LCD_i++;
            
            LCD_j=0;
        }
        break;    
        
        case 44:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_dizi[1][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;   
        }
        break;  
        
        case 45:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_mesajlari[LCD_satir3][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;   
        }
        break;  
        
        case 46:
        {
            if(LCD_satir2)
            LCD_i++;
            
            LCD_j=0;
        }
        break;
        
        case 47:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_dizi[2][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;
            
        
        }
        break; 
        
        case 48:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_mesajlari[LCD_satir2][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;
            
        
        }
        break; 
        
        case 49:
        {
        if(LCD_satir4)
            LCD_i++;
            
            LCD_j=0;
        }
        break;    
        
        case 50:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_dizi[3][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;
        
        }
        break; 

        case 51:
        {
            if(LCD_j<LCD_sutun)
            {
                LCD_data=LCD_mesajlari[LCD_satir4][LCD_j]; //3. satir yaziliyor

                LCD_j++;

                LCD_data_h=LCD_data>>4;
                LCD_data_l=LCD_data&0xf;

                LCD_don=(LCD_i-1);
                LCD_i=yaz;
                
            } 
            else
            LCD_j=0;
        
        }
        break;
        
        case 52: //bitti
        {
            LCD_rfrsh=0;
            LCD_i=0;

        }
        break;

        case yaz1:
        {
            if(LCD_data_h&(0b00000001)) LED5_SetHigh(); else LED5_SetLow();
            if(LCD_data_h&(0b00000010)) LED6_SetHigh(); else LED6_SetLow();
            if(LCD_data_h&(0b00000100)) LED7_SetHigh(); else LED7_SetLow();
            if(LCD_data_h&(0b00001000)) LED8_SetHigh(); else LED8_SetLow();

        }
        break;

        case yaz2:
        {
            LCD_EN_SetHigh();
        }
        break;

        case yaz3:
        {
            LCD_EN_SetLow();
        }
        break;

        case yaz4:
        {
            if(LCD_data_l&(0b00000001)) LED5_SetHigh(); else LED5_SetLow();
            if(LCD_data_l&(0b00000010)) LED6_SetHigh(); else LED6_SetLow();
            if(LCD_data_l&(0b00000100)) LED7_SetHigh(); else LED7_SetLow();
            if(LCD_data_l&(0b00001000)) LED8_SetHigh(); else LED8_SetLow();

        }
        break;

        case yaz5:
        {
            LCD_EN_SetHigh();
        }
        break;

        case yaz6:
        {
            LCD_EN_SetLow();
            LCD_i=LCD_don; //yazma islemi bitince nereye geri donecek
        }
        break;
    
    
    }
    
    
}



void lcd_init(void)
{
    GLCD_DI_SetLow();
    GLCD_RW_SetLow();
    LCD_EN_SetLow();
    DELAY_milliseconds(15);
    
    lcd_send_nibble(3); //lcd ye 4bit kullancagimizi soyluyoruz
    DELAY_milliseconds(5);
    lcd_send_nibble(3);
    DELAY_milliseconds(5);
    lcd_send_nibble(3);
    DELAY_milliseconds(5);
    
    lcd_send_nibble(2);
    DELAY_milliseconds(5);
    
    lcd_send_byte(0,0x28); //5x7 4 bit  2 satir
    lcd_send_byte(0,0x08); // lcd off, imleci gizle
    lcd_send_byte(0,0x01); // clear lcd
    lcd_send_byte(0,0x06); // giris modu
    
    DELAY_milliseconds(50);
    lcd_send_byte(0,0x28);  //5x7 4 bit  2 satir
    lcd_send_byte(0,0x0c);  // lcd on, imleci ac, imlec no blink
    lcd_send_byte(0,0x06);  // giris modu
    lcd_send_byte(0,0x01);  // clear lcd
    DELAY_milliseconds(5);
    
    
}
void lcd_send_byte(unsigned char address, unsigned char n)
{

    LCD_EN_SetLow();
    GLCD_RW_SetLow();
    DELAY_milliseconds(3);
    
    if(address)
        GLCD_DI_SetHigh(); //data
    else
        GLCD_DI_SetLow(); //komut
    
    DELAY_milliseconds(3);
    
    lcd_send_nibble(n >> 4);
    DELAY_microseconds(5);
    lcd_send_nibble(n & 0xf);
    
}

void lcd_send_nibble(unsigned char n)
{
    GLCD_RW_SetLow();
    
    LCD_data=n;
    
    if(LCD_data&(0b00000001)) LED5_SetHigh(); else LED5_SetLow();
    if(LCD_data&(0b00000010)) LED6_SetHigh(); else LED6_SetLow();
    if(LCD_data&(0b00000100)) LED7_SetHigh(); else LED7_SetLow();
    if(LCD_data&(0b00001000)) LED8_SetHigh(); else LED8_SetLow();
    
    DELAY_microseconds(5);
    LCD_EN_SetHigh();
    DELAY_microseconds(5);
    LCD_EN_SetLow();
    DELAY_microseconds(5);
    
    
}
void LCD_sayi_yaz(unsigned char satir, unsigned char sutun, unsigned char uzunluk, unsigned int sayi)
{
    unsigned char zz=0;
    
    switch(satir)
    {   
        case 1: lcd_send_byte(0,LCD_satir1_adr+sutun); break;
        case 2: lcd_send_byte(0,LCD_satir2_adr+sutun); break;
        case 3: lcd_send_byte(0,LCD_satir3_adr+sutun); break;
        case 4: lcd_send_byte(0,LCD_satir4_adr+sutun); break;
    
    }
    
    cevir(sayi,BCD_disp,uzunluk,48);
    
    for(zz=0; zz<4; zz++)
    lcd_send_byte(1,BCD_disp[zz]);
}
void LCD_cumleyaz(unsigned char satir, unsigned char sutun, unsigned char uzunluk, unsigned char* point)
{
    unsigned char yy=0;
    switch(satir)
    {   
        case 1: lcd_send_byte(0,LCD_satir1_adr+sutun); break;
        case 2: lcd_send_byte(0,LCD_satir2_adr+sutun); break;
        case 3: lcd_send_byte(0,LCD_satir3_adr+sutun); break;
        case 4: lcd_send_byte(0,LCD_satir4_adr+sutun); break;
    
    }
    
    for(yy=0; yy<uzunluk; yy++)
    lcd_send_byte(1, point[yy]);
}