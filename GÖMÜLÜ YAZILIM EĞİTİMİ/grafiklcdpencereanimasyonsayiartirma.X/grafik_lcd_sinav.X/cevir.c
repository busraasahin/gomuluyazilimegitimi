

// cevir.h dosyasýný projeye ekle


// bu dosyadaki fonksiyonlar LCD_rfrsh pasifken çaðýrýlýyor.
// yani deðiþkenler deðiþirken paralelde LCD'ye yazdýrma yapýlmýyor

#include"cevir.h"

unsigned long fark[]={1,10,100,1000,10000,100000,1000000,10000000};

volatile signed char digit=0;
volatile unsigned char dig_fark=0;


void topla(unsigned char *kaynak, unsigned char uzunluk, unsigned char ascii)
{
    unsigned int sonuc=0;
    
    digit=uzunluk;
    
    while(digit)
    {
        dig_fark=uzunluk-digit;
		
		digit--;
        
        sonuc+=(kaynak[digit]-ascii)*fark[digit];
    }    
}

void cevir(unsigned long veri, unsigned char *hedef, unsigned char uzunluk,unsigned char ascii)
{
	digit=uzunluk;	

	while(digit)
	{
		dig_fark=uzunluk-digit;
		
		digit--;		
			
		hedef[dig_fark]=ascii;				

		while(veri>(fark[digit]-1))
		{			
			hedef[dig_fark]++;
			veri-=fark[digit];			
		}				
	}
}



void pcevir(unsigned long veri, unsigned char *hedef, unsigned char uzunluk,unsigned char nokta)
{	
	for(digit=0;digit<=uzunluk;digit++)
	hedef[digit]=48;

	while(digit)
	{
		dig_fark=uzunluk-digit;
		
		digit--;			

		while(veri>(fark[digit]-1))
		{
			veri-=fark[digit];
			
			if(dig_fark<nokta)
			hedef[(dig_fark)]++;
			else
			hedef[(dig_fark+1)]++;			
		}				
	}

	hedef[nokta]='.';
}
