#ifndef __NRF24_HAL_H
#define __NRF24_HAL_H

// Hardware abstraction layer for NRF24L01+ transceiver (hardware depended functions)

// Peripheral libraries
#include "main.h"
#include "gpio.h"
//#include "stm32g0xx_hal_spi.h"

// Macros for the RX on/off
#define nRF24_RX_ON		nRF24_CE_H()
#define nRF24_RX_OFF	nRF24_CE_L()

// CE (chip enable)
// #define nRF24_CE_L		HAL_GPIO_WritePin(nRF24_CE_GPIO_Port, nRF24_CE_Pin, GPIO_PIN_RESET)
// #define nRF24_CE_H		HAL_GPIO_WritePin(nRF24_CE_GPIO_Port, nRF24_CE_Pin, GPIO_PIN_SET)

// CSN (chip select negative)
// #define nRF24_CSN_L		HAL_GPIO_WritePin(nRF24_CSN_GPIO_Port, nRF24_CSN_Pin, GPIO_PIN_RESET)
// #define nRF24_CSN_H		HAL_GPIO_WritePin(nRF24_CSN_GPIO_Port, nRF24_CSN_Pin, GPIO_PIN_SET)

// IRQ pin
// CubeMX defines this pin in main.h

// Function prototypes
uint8_t nRF24_LL_RW(uint8_t spi_tx_data);
void nRF24_CE_L(void);
void nRF24_CE_H(void);
void nRF24_CSN_L(void);
void nRF24_CSN_H(void);

#endif // __NRF24_HAL_H
