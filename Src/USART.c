/**
 ******************************************************************************
 * @file            USART.c
 * @author          Maxime 
 * @brief           Source file for 8 bits PIC18 MCUs USART API
 * @brief           See USART.h 
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

//-----------------------------------
#include "../Inc/USART.h"
#include "../Inc/SystemTime.h"
//-----------------------------------

void USARTSetBGR(uint8_t bgr)
{
    //---------
    SPBRG = bgr;
    //---------    
}
//-----------------------------------------

void USARTSetBaudRate(uint32_t baud)
{
    //---------
    uint8_t q = 1;uint32_t val = 1;
    //---------
    if(TXSTA,SYNC)
    {
        q = 4;
    }
    else
    {
        if(TXSTA,BRGH)
            q = 16;
        else
            q = 64;
    }
    //---------
    val = ((FOSC_MHZ * 1000000/(q * baud)) - 1);
    //---------
    SPBRG = (uint8_t)val;
    //---------
}
//-----------------------------------------

void USARTInit(ConfigType cfg)
{
    //---------
    TXSTA = cfg.grp1;
    RCSTA = cfg.grp2; 
    //---------
}
//-----------------------------------------

void USARTAsyncInit(uint8_t bgr)
{
    //---------
    TXSTA = 0x24;                   //!< Asynchronous mode, 8 bits transmit/receive, high speed, transmitter disabled.
    RCSTA = 0x90;                   //!< USART enable, 8 bits reception, Receiver disabled 
    SPBRG = bgr;
    //---------    
}
//-----------------------------------------

void USARTTransmitByte9(uint16_t data)
{
    //---------
    while(TXSTA,TRMT == 0);                 //!< Last transmit completed?
    //---------
    if(data & 0x100)
        TXSTA |= 0x01;                      //!< 9th bit is 1
    else
        TXSTA &= 0xFE;                      //!< 9th bit is 0
    //---------
    TXREG = (uint8_t)(data & 0xFF);
    //--------- 
}
//-----------------------------------------

void USARTTransmitBytes(uint8_t *data, uint16_t cnt)
{
    //---------
    while(cnt != 0)
    {
        USARTTransmitByte(*data);
        ++data;
        --cnt;
    }
    //---------    
}
//-----------------------------------------

void USARTTransmitBytes9(uint16_t *data, uint16_t cnt)
{
    //---------
    while(cnt != 0)
    {
        USARTTransmitByte9(*data);
        ++data;
        --cnt;
    }
    //---------     
}
//-----------------------------------------

void USARTPrint(const char *str)
{
    while(*str!='\0'){
        while(TXSTA,TRMT == 0);
        TXREG = *str;
        ++str;
    }    
}
//-----------------------------------------

uint8_t USARTReceiveByte(void)
{
    //---------    
    uint8_t data = RCREG;
    //---------
    if(RCSTA,OERR)
        RCSTA,CREN = 0; 
    //---------
    return data;     
}
//-----------------------------------------

uint16_t USARTReceiveByte9(void)
{
    //---------    
    uint16_t data = RCREG;
    data |= (uint16_t)((RCSTA & 0x01) << 8);
    //---------
    if(RCSTA,OERR)
        RCSTA,CREN = 0; 
    //---------
    return data;    
}
//-----------------------------------------

uint16_t USARTReceiveBytes(uint8_t *data, uint16_t cnt, uint32_t tout)
{
    //---------
    unsigned char j = 0;
    uint32_t time = Tick_ms(); 
    while(cnt != 0)
    {
        //---------
        if(USARTRxAvailable()){
            *data = USARTReceiveByte();
            ++data;
            ++j;
        }
        //---------
        if((Tick_ms() - time) >= tout)
            break;
    }
 return j;
    //---------    
}
//-----------------------------------------

uint16_t USARTReceiveBytes9(uint16_t *data, uint16_t cnt, uint32_t tout)
{
    //---------
    unsigned char j = 0;
    uint32_t time = Tick_ms(); 
    while(cnt != 0)
    {
        //---------
        if(USARTRxAvailable()){
            *data = USARTReceiveByte9();
            ++data;
            ++j;
        }
        //---------
        if((Tick_ms() - time) >= tout)
            break;
    }
 return j;
    //---------    
}
//-----------------------------------------