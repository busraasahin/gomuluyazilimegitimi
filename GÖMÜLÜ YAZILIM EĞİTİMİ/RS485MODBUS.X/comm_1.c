
#include  <xc.h>
#include "mcc_generated_files/uart1.h"
#include "comm_1.h"
#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/pin_manager.h"

unsigned char com_peryot=0;
unsigned char tx_buffer[30]="Busra SAHIN";
unsigned char tx_indis=0;
unsigned char gidecek_veri=0;

unsigned char rx_buffer[30];
unsigned char rx_indis=0;

unsigned char com1_timeout=0;
unsigned char paket_geldi=0;

unsigned char Modbus_Status=0;
unsigned char device_address=1;

unsigned char rx_indisx=0;

unsigned char *crc_adr=0;
unsigned char crc_adet=0;
unsigned int  ui16_crc=0xffff;
unsigned char crc_don=0;
unsigned char CRC_h=0, CRC_l=0, bb=0;
unsigned int cik_bekle=0;

unsigned char modbus_goster=0;
unsigned char modbus_cevap=0;

union dataform_1 modbus_degiskenleri[20],temp_coils[10];
volatile unsigned char *modbus_pointer=(unsigned char *)(&modbus_degiskenleri[0].bytes[0]);
volatile unsigned char *point_coils=(unsigned char *)(&temp_coils[0].bytes[0]);

unsigned char reg_adres=0,veri_sayisi=0,veri_say=0;


bool bit_temp=0;
unsigned long temp_dword=0;

unsigned int saniye_say=0;

void modbus(void) //T?mwe ISR içersinde her 100 usn de 1 kez cagiriliyor
{
    receive_2();
     
     if(com_peryot<20) //2msde bir gonder
        com_peryot++;
     else 
     {   
        com_peryot=0;
        
        //master kodu slave de olmayacak***
        if(gidecek_veri==0)
            rs485_dir_SetLow(); //dinleme durumuna gore
       
        if(saniye_say<500)  
            saniye_say++;
        else 
        {    
            rs485_dir_SetHigh(); //gonderme durumuna gec 
        
            saniye_say=0;
            
            tx_buffer[0]=0X01;
            tx_buffer[1]=0X10;
            tx_buffer[2]=0X00;
            tx_buffer[3]=0X01;
            tx_buffer[4]=0X00;
            tx_buffer[5]=0X02;
            tx_buffer[6]=0X04;
            tx_buffer[7]=0X00;
            tx_buffer[8]=0X0A;
            tx_buffer[9]=0X01;
            tx_buffer[10]=0X02;
            tx_buffer[11]=0X92;
            tx_buffer[12]=0X30;
            
            
            
            modbus_cevap=1;
            gidecek_veri=13;
        }
        
        if(com1_timeout<10) //20msn'de timeout
        com1_timeout++;
        else
        { 
            if(rx_indis>0)
            {    
                paket_geldi=1;
                rx_indisx=rx_indis;
            }
            
            rx_indis=0;
        } 
            
        
        send_2();
    }
     master_gelengoster(); //master'da acik kalacak
    // slave_cevap();  //slave de acik kalacak
     
}
void receive_2(void)
{
    if ((U2STAbits.OERR == 1))
    {
        U2STAbits.OERR = 0;
    }    
        
    if(U2STAbits.URXDA == 1) //gelen veri hazir
    {
         com1_timeout=0;
         
         rx_buffer[rx_indis]=U2RXREG;
         
         if(rx_indis<19)
         rx_indis++;
                 
    }
}
void send_2(void)
{
    if(gidecek_veri>0)
        {    
            
        if(U2STAbits.UTXBF == 0) //transmit buffer bosalmissa
           {
           U2TXREG=tx_buffer[tx_indis];
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

void master_gelengoster(void)
{
        if(paket_geldi)
        {   
            paket_geldi=0;
            modbus_cevap=1;
        }
}

void slave_cevap(void)
{
    switch (Modbus_Status)  //100usn'de bir kez calisiyor
        {
            case 0: //bekleme durumu
            {
                rs485_dir_SetLow();
                
                if(paket_geldi)
                {   
                    Modbus_Status++;
                    paket_geldi=0;
                }
            } 
            break; 
            
            case 1: 
            {
                if(rx_buffer[0]==device_address) //adres bizimkiyse
                {    
                    tx_buffer[0]=device_address;
                    modbus_cevap=1;
                    
                    Modbus_Status++;
                    crc_adr=rx_buffer;
                    crc_adet=rx_indisx-2;
                    ui16_crc=0xffff; //16 bit icin baslangic degeri
                    crc_don=3;
                }
                else
                    Modbus_Status=0;
            } 
            break;
            
            case crc_calculate: // crc calculate
            {
                if(crc_adet--)
                {
                    ui16_crc ^= *crc_adr++;
                    
                    for (bb=8; bb !=0; bb--)
                    {
                        if(ui16_crc & 1)
                        ui16_crc= (ui16_crc >> 1) ^ ((unsigned int)0xA001);
                        else
                        ui16_crc >>=1;    
                    }    
                }
                else
                {
                    CRC_l=(unsigned char)(ui16_crc & 0xFF);
                    CRC_h=(unsigned char)((ui16_crc>>8)&0xFF);
                    
                    Modbus_Status=crc_don;
                }    
            }
            break;
            
            case 3: //crc check
            {
                if((CRC_l==rx_buffer[rx_indisx-2])&&(CRC_h==rx_buffer[rx_indisx-1]))
                {
                        crcl_rx=CRC_l;
                        crch_rx=CRC_h;
                        
                        Modbus_Status++;
                        modbus_goster=1;
                }
                else
                {
                    Modbus_Status=0; //CRC hatasinda basa don
                    // CRC hatasiyle ilgili kayit tutmak icin b
                    //burada isaretleme yap
                }
            }
            break;
            
            case 4: // define function
            {
                switch(rx_buffer[1])
                {
                    case 1:  Modbus_Status=read_coils;                  break;
                    case 2:  Modbus_Status=read_discrete_inputs;        break;
                    case 3:  Modbus_Status=read_holding_registers;      break;
                    case 4:  Modbus_Status=read_input_registers;        break;
                    case 5:  Modbus_Status=write_single_coil;           break;
                    case 6:  Modbus_Status=write_single_register;       break;
                    case 8:  Modbus_Status=diagnostics;                 break;
                    case 11: Modbus_Status=get_comm_event_counter;      break;
                    case 15: Modbus_Status=write_multiple_coils;        break;
                    case 16: Modbus_Status=write_multiple_registers;    break;
                    case 17: Modbus_Status=report_server_id;            break;
                    case 22: Modbus_Status=mask_write_register;         break;
                    case 23: Modbus_Status=rw_multiple_registers;       break;
                    case 43: Modbus_Status=read_device_id;              break;
                    
                    default: Modbus_Status=modbus_cik;                  break;
                    
                }        
                
                rs485_dir_SetHigh(); //artiik gonderecegiz (cevap)
            }
            break;
            
            case write_single_coil:
            {
                tx_buffer[1]=5; //function adres
                tx_buffer[2]=rx_buffer[2]; 
                tx_buffer[3]=rx_buffer[3];
                tx_buffer[4]=rx_buffer[4];
                tx_buffer[5]=rx_buffer[5];
                modbus_cevap=1;
                
                veri_sayisi=rx_buffer[3]; //172
                veri_say=0;
                temp_coils[0].dword=0;
                
                while(veri_sayisi>31)
                {
                    veri_sayisi=veri_sayisi-32;
                    veri_say++;
                }    
                //veri_say=5;
                //kalan=12;
               
                temp_coils[0].bytes[0]=rx_buffer[5];
                temp_coils[0].bytes[1]=rx_buffer[4];
                
                (temp_coils[0].dword)=(temp_coils[0].dword)<<(veri_sayisi);
                
                modbus_degiskenleri[veri_say].dword=(modbus_degiskenleri[veri_say].dword)|(temp_coils[0].dword);
                
                temp_coils[0].word[1]=0xFFFF; //her biti1 yap
                temp_coils[0].bytes[0]=rx_buffer[5];
                temp_coils[0].bytes[1]=rx_buffer[4];
                
                while (veri_sayisi>0)
                {
                    temp_coils[0].dword<<1;
                    temp_coils[0].dword|=1;
                    veri_sayisi--;
                    
                }
                
                modbus_degiskenleri[veri_say].dword=(modbus_degiskenleri[veri_say].dword)&(temp_coils[0].dword);
                
                Modbus_Status=crc_calculate;
                crc_adr=tx_buffer; //transmit buffer dizisiinin adresini ifade ediyor.
                crc_adet=6; 
                ui16_crc=0xffff;
                crc_don=write_single_coil_cont;
             
            }
            break;
            
            case write_single_coil_cont:
            {
                tx_buffer[6]=CRC_l;
                tx_buffer[7]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=8;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
            }
            break;
            
            case read_coils:
            {
                tx_buffer[1]=1; //function adres
                tx_buffer[2]=2;
                
                if(rx_buffer[3]<32)
                {    
                    if((rx_buffer[3]+rx_buffer[5]<32))
                    {    
                    temp_coils[0].dword=(modbus_degiskenleri[0].dword)>>(rx_buffer[3]); //adres kadar saga kaydir
                    
                        //ilk alandan baslayip devaminde diger alanlara 
                        //uzanan isteklere gore sekillendir
                    
                    }
                }
                else
                {
                    temp_coils[0].dword=(modbus_degiskenleri[1].dword)>>(rx_buffer[3]-32);
                }
               
                tx_buffer[3]=point_coils[0];
                tx_buffer[4]=point_coils[1];
                modbus_cevap=1;
                
                Modbus_Status=crc_calculate;
                crc_adr=tx_buffer; //transmit buffer dizisiinin adresini ifade ediyor.
                crc_adet=5; 
                ui16_crc=0xffff;
                crc_don=read_coils_cont;
            }
            break;
            
            case read_coils_cont:
            {
                tx_buffer[5]=CRC_l;
                tx_buffer[6]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=7;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
            }
            break;
            
            case write_multiple_registers: //istenilenden baslayip istedigimizi yazdirma
            {
                tx_buffer[1]=16; //function adres
                tx_buffer[2]=rx_buffer[2];
                tx_buffer[3]=rx_buffer[3];
                tx_buffer[4]=rx_buffer[4];
                tx_buffer[5]=rx_buffer[5];
                modbus_cevap=1;
                reg_adres=rx_buffer[3];
                
                //write register islemi
                for(veri_say=0; veri_say<(rx_buffer[5]); veri_say++)
                {
                    modbus_pointer[reg_adres*2+1+(2*veri_say)]=rx_buffer[7+(2*veri_say)];
                    modbus_pointer[reg_adres*2+(2*veri_say)]=rx_buffer[8+(2*veri_say)];
                }
                
                Modbus_Status=crc_calculate;
                crc_adr=tx_buffer; //transmit buffer dizisiinin adresini ifade ediyor.
                crc_adet=6; //her zman cevap 6 byte
                ui16_crc=0xffff;
                crc_don=write_multiple_registers_cont;
            }
            break;
            
            case write_multiple_registers_cont:
            {
                tx_buffer[6]=CRC_l;
                tx_buffer[7]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=8;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
            }
            break;
            
            case write_single_register: 
            {
                tx_buffer[1]=6; //function adres
                tx_buffer[2]=rx_buffer[2];
                tx_buffer[3]=rx_buffer[3];
                tx_buffer[4]=rx_buffer[4];
                tx_buffer[5]=rx_buffer[5];
                modbus_cevap=1;
                reg_adres=rx_buffer[3];
                
                //register write islemi
                modbus_pointer[reg_adres*2+1]=rx_buffer[4];
                modbus_pointer[reg_adres*2]=rx_buffer[5];
                
                
                Modbus_Status=crc_calculate;
                crc_adr=tx_buffer; //transmit buffer dizisiinin adresini ifade ediyor.
                crc_adet=6; //her zman cevap 6 byte
                ui16_crc=0xffff;
                crc_don=write_single_register_cont;
            }
            break;
            
            case write_single_register_cont:
            {
                tx_buffer[6]=CRC_l;
                tx_buffer[7]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=8;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
            }
            break;
            
            case read_holding_registers: //1 den fazla register okunmasi
            {
                tx_buffer[1]=3;
                tx_buffer[2]=2*(rx_buffer[5]); //1 bytel?k  çal??ma icin 
                veri_sayisi=3+tx_buffer[2];
                reg_adres=rx_buffer[3];
               
                for(veri_say=0; veri_say<(rx_buffer[5]); veri_say++)
                {
                    tx_buffer[3+(2*veri_say)]=modbus_pointer[reg_adres*2+1+(2*veri_say)];
                    tx_buffer[4+(2*veri_say)]=modbus_pointer[reg_adres*2+(2*veri_say)];
                }    

                
                
                modbus_cevap=1;
                
                //rx_buffer[2] //adres H
                //rx_buffer[4] //adres H
                //rx_buffer[5] //adres L
                Modbus_Status=crc_calculate;
                crc_adr=tx_buffer; //transmit buffer dizisiinin adresini ifade ediyor.
                crc_adet=veri_sayisi;
                
                ui16_crc=0xffff;
                crc_don=read_holding_registers_cont;
                
            }
            break;
            
            case read_holding_registers_cont:
            {
                tx_buffer[veri_sayisi]=CRC_l;
                tx_buffer[veri_sayisi+1]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=veri_sayisi+2;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
            }
            break;
            
            case read_device_id: //1 byte okunmak istenirse
            {
                    tx_buffer[1]=rx_buffer[1];
                    tx_buffer[2]=device_address;
                    modbus_cevap=1;
                    
                    Modbus_Status=crc_calculate;
                    crc_adr=tx_buffer;
                    crc_adet=3;
                    ui16_crc=0xffff; //16 bit icin baslangic degeri
                    crc_don=read_device_id_cont;
            }
            break;
            
            case read_device_id_cont:
            {
                tx_buffer[3]=CRC_l;
                tx_buffer[4]=CRC_h;
                modbus_cevap=1;
                
                gidecek_veri=5;
                cik_bekle=((unsigned int)gidecek_veri)*20;
                Modbus_Status=modbus_cik;
                
            }
            break;
            
            case modbus_cik:
            {
                if(cik_bekle>0)
                    cik_bekle--;
                else 
                    Modbus_Status=0;
            }
            break;
            
        } 
}

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
            {    
                paket_geldi=1;
                rx_indisx=rx_indis;
            }
            
            rx_indis=0;
        } 
               
        
        send();
    }
     
     slave_cevap();
    
}