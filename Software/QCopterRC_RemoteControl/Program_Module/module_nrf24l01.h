/* #include "module_nrf24l01.h" */

#ifndef __MODULE_NRF24L01_H
#define __MODULE_NRF24L01_H

#include "stm32f4xx.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define nRF_SPI         SPI3  // nRF 使用 SPI3

#define TXBUF_SIZE      32
#define RXBUF_SIZE      32

#define TX_ADR_WIDTH    5     // 發射地址寬度
#define TX_PLOAD_WIDTH  32    // 發射數據通道有效數據寬度 0~32Byte

#define RX_ADR_WIDTH    5
#define RX_PLOAD_WIDTH  32

#define CHANAL          40    // 頻道選擇

// Commands
#define NRF_READ        0x00  // Define read command to register
#define NRF_WRITE       0x20  // Define write command to register
#define RD_RX_PLOAD     0x61  // Define RX payload register address
#define WR_TX_PLOAD     0xA0  // Define TX payload register address
#define FLUSH_TX        0xE1  // Define flush TX register command
#define FLUSH_RX        0xE2  // Define flush RX register command
#define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
#define NOP             0xFF  // Define No Operation, might be used to read status register

// Registers ( Addr )
#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define CD              0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address

#define MAX_RT          0x10  // 達到最大重發次數中斷標誌位
#define TX_DS           0x20  // 發送完成中斷標誌位

#define RX_DR           0x40  // 接收到數據中斷標誌位
/*=====================================================================================================*/
/*=====================================================================================================*/
void nRF24L01_Config( void );

u8   nRF_Check( void );

void nRF_WriteReg( u8 WriteAddr, u8 WriteData );
u8   nRF_ReadReg( u8 ReadAddr );
void nRF_WriteBuf( u8 WriteAddr, u8 *WriteBuf, u8 Bytes );
void nRF_ReadBuf( u8 ReadAddr, u8 *ReadBuf, u8 Bytes );

void nRF_RX_Mode( void );
void nRF_TX_Mode( void );
u8   nRF_Tx_Data( u8 *TxBuf );
u8   nRF_Rx_Data( u8 *RxBuf );

void nRF_Recv_IRQ( void );
/*====================================================================================================*/
/*====================================================================================================*/
extern u8 TxBuf[TXBUF_SIZE];
extern u8 RxBuf[RXBUF_SIZE];
/*====================================================================================================*/
/*====================================================================================================*/
#endif
