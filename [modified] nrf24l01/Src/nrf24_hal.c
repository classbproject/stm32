#include "nrf24_hal.h"
#include "main.h"
#include "spi.h"

extern SPI_HandleTypeDef hspi1;

// Low level SPI transmit/receive function (hardware depended)
// input:
//   spi_tx_data - value to transmit via SPI
// return: value received from SPI

uint8_t nRF24_LL_RW(uint8_t spi_tx_data)
{
	uint8_t spi_rx_data;

	if (HAL_SPI_TransmitReceive(&hspi1, &spi_tx_data, &spi_rx_data, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		Error_Handler();
	}

	return spi_rx_data;
}

void nRF24_CE_L(void)
{
	HAL_GPIO_WritePin(nRF24_CE_GPIO_Port, nRF24_CE_Pin, GPIO_PIN_RESET);
	//HAL_Delay(1);
}

void nRF24_CE_H(void)
{
	HAL_GPIO_WritePin(nRF24_CE_GPIO_Port, nRF24_CE_Pin, GPIO_PIN_SET);
	//HAL_Delay(1);
}

void nRF24_CSN_L(void)
{
	HAL_GPIO_WritePin(nRF24_CSN_GPIO_Port, nRF24_CSN_Pin, GPIO_PIN_RESET);
	//HAL_Delay(1);
}

void nRF24_CSN_H(void)
{
	HAL_GPIO_WritePin(nRF24_CSN_GPIO_Port, nRF24_CSN_Pin, GPIO_PIN_SET);
	//HAL_Delay(1);
}

