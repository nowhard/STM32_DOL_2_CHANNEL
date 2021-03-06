#ifndef SPI_BUS_H
#define SPI_BUS_H

#include "stm32f4xx.h"
#include "indicator.h"

#define SPI1_GPIO_BUS 	RCC_AHB1Periph_GPIOB
#define SPI1_GPIO		GPIOB

#define SPI1_CS1	GPIO_Pin_6
#define SPI1_CS2	GPIO_Pin_7

struct bus
{
	uint8_t indicators_num;
	uint16_t bus_buf[IND_SPI_BUS_1_NUM][IND_COMMAND_LEN];
	uint8_t error;
};

#define BUS_NUM	1


enum
{
	 BUS_SPI_1=0,
	 BUS_SPI_2=1,
	 BUS_SPI_3=2,
};

enum
{
	BUS_ERROR_NONE	=0,
	BUS_ERROR_POWER=1
};

uint8_t spi_buses_init(void);

void	spi1_config(void);
void	spi2_config(void);
void 	spi3_config(void);

void spi1_write_buf(uint16_t* pBuffer, uint16_t len);//
void spi1_read_buf(uint16_t* pBuffer, uint16_t len);
void spi2_write_buf(uint16_t* pBuffer, uint16_t len);
void spi2_read_buf(uint16_t* pBuffer, uint16_t len);
void spi3_write_buf(uint16_t* pBuffer, uint16_t len);
void spi3_read_buf(uint16_t* pBuffer, uint16_t len);

#endif
