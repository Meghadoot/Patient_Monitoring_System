// HAL SPI Header File
#ifndef HAL_SPI_H
#define HAL_SPI_H

void HAL_SPI_Init(int bus);
void HAL_SPI_Transfer(int bus, const uint8_t *txData, uint8_t *rxData, int length);

#endif // HAL_SPI_H
