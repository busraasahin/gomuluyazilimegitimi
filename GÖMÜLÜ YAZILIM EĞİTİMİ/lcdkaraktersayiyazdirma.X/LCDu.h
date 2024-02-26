
#define yaz     59
#define yaz1    60
#define yaz2    61
#define yaz3    62
#define yaz4    63
#define yaz5    64
#define yaz6    65


#define LCD_sutun    20
#define LCD_satir    4

//disaridan erisilmek istenen kisimlar dahil edilir.
extern unsigned char LCD_rfrsh;
extern unsigned char LCD_dizi[LCD_satir][LCD_sutun];
extern unsigned char LCD_satirx[LCD_satir];

#define LCD_satir1   LCD_satirx[0]
#define LCD_satir2   LCD_satirx[1]
#define LCD_satir3   LCD_satirx[2]
#define LCD_satir4   LCD_satirx[3]



#define LCD_satir1_adr   0x80
#define LCD_satir2_adr   0xc0
#define LCD_satir3_adr   0x94
#define LCD_satir4_adr   0xd4


void LCD(void);

void LCD_cumleyaz(unsigned char satir, unsigned char sutun, unsigned char uzunluk, unsigned char* point);
void LCD_sayi_yaz(unsigned char satir, unsigned char sutun, unsigned char uzunluk, unsigned int sayi);

void lcd_init(void);
void lcd_send_byte(unsigned char address, unsigned char n);
void lcd_send_nibble(unsigned char n);


