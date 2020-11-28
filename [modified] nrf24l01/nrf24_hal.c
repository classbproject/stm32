#include "nrf24_hal.h"
#include "main.h"
#include "spi.h"

extern SPI_HandleTypeDef hspi1;

// Low level SPI transmit/receive function (hardware depended)
// input:
//   spi_tx_data - value to transmit via SPI
// return: value received from SPI

uint8_t nRF24_LL_RW (uint8_t spi_tx_data)
{
	uint8_t spi_rx_data;

	if (HAL_SPI_TransmitReceive (&hspi1, &spi_tx_data, &spi_rx_data, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		Error_Handler ();
	}

	return spi_rx_data;
}
