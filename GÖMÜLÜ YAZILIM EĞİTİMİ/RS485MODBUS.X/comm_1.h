    #define crc_calculate                    2
    #define modbus_cik                       10


    #define read_coils                       20
    #define read_coils_cont                  21
    #define read_discrete_inputs             22
    #define read_discrete_inputs_cont        23
    #define read_holding_registers           24
    #define read_holding_registers_cont      25
    #define read_input_registers             26
    #define read_input_registers_cont        27
    #define write_single_coil                28
    #define write_single_coil_cont           29
    #define write_single_register            30
    #define write_single_register_cont       31
    #define diagnostics                      32
    #define diagnostics_cont                 33
    #define get_comm_event_counter           34
    #define get_comm_event_counter_cont      35
    #define write_multiple_coils             36
    #define write_multiple_coils_cont        37
    #define write_multiple_registers         38
    #define write_multiple_registers_cont    39
    #define report_server_id                 40
    #define report_server_id_cont            41
    #define mask_write_register              42
    #define mask_write_register_cont         43
    #define rw_multiple_registers            44
    #define rw_multiple_registers_cont       45
    #define read_device_id                   46
    #define read_device_id_cont              47
    #define function_err                     48
    #define function_err_cont                49








extern unsigned char tx_buffer[30];
extern unsigned char tx_indis;
extern unsigned char gidecek_veri; 

extern unsigned char rx_buffer[30];
extern unsigned char rx_indis;
extern unsigned char paket_geldi;

extern unsigned char com1_timeout;

extern unsigned char CRC_h, CRC_l;
extern unsigned char modbus_goster;
extern unsigned char modbus_cevap;

extern unsigned char crch_rx, crcl_rx;


union dataform_1
{
    signed long dword; //32 bit
    unsigned int  word[2]; //16bit
    unsigned char bytes[4]; //8 bit
    
    struct bitler
    {
        bool bit0:1;
        bool bit1:1;
        bool bit2:1;
        bool bit3:1;
        bool bit4:1;
        bool bit5:1;
        bool bit6:1;
        bool bit7:1;
        bool bit8:1;
        bool bit9:1;
        bool bit10:1;
        bool bit11:1;
        bool bit12:1;
        bool bit13:1;
        bool bit14:1;
        bool bit15:1;
        bool bit16:1;
        bool bit17:1;
        bool bit18:1;
        bool bit19:1;
        bool bit20:1;
        bool bit21:1;
        bool bit22:1;
        bool bit23:1;
        bool bit24:1;
        bool bit25:1;
        bool bit26:1;
        bool bit27:1;
        bool bit28:1;
        bool bit29:1;
        bool bit30:1;
        bool bit31:1;
        
        
    } bits;
    
};

//modbus_degiskenleri[0].dword=100000; //32 bit erisim 
//modbus_degiskenleri[1].word[0]=

void receive (void);
void send (void);
void haberles (void);

void modbus(void);
void receive_2(void);
void send_2(void);

void master_gelengoster(void);
void slave_cevap(void);
