/*
 * SPI_config.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Kerolos
 */

#ifndef INCLUDE_MCAL_SPI_SPI_CONFIG_H_
#define INCLUDE_MCAL_SPI_SPI_CONFIG_H_

/*SPI CONROL REG (SPCR)*/
#define SPI_INTERRUPT_ENABLE 0
#define SPI_ENABLE 1
#define DATA_ORDER 0           /*When the DORD bit is written to one, the LSB of the data word is transmitted first. \
                               When the DORD bit is written to zero, the MSB of the data word is transmitted first.*/
#define MSTR_SLAVE_SELECT MSTR /*1=>MSTR \
                            0=>SLAVE*/
#define CLOCK_POLARITY 1       /*0 Rising Falling \
                               1 Falling Rising*/

#define CLOCK_PHASE 1 /*0 Sample Setup \
                        1 Setup Sample*/

#define SPR1 1
#define SPR0 0

#define SPI2X DOUBLE_SPEED_OFF // When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when

/*SPI2X SPR1 SPR0 SCK Frequency
    0 0 0 fosc/4
    0 0 1 fosc/16
    0 1 0 fosc/64
    0 1 1 fosc/128
    1 0 0 fosc/2
    1 0 1 fosc/8
    1 1 0 fosc/32
    1 1 1 fosc/64*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* INCLUDE_MCAL_SPI_SPI_CONFIG_H_ */
