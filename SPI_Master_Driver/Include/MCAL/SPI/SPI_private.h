/*
 * SPI_private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Kerolos
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRIVATE_H_
#define INCLUDE_MCAL_SPI_SPI_PRIVATE_H_

#define SPI_SPCR (*(volatile u8 *)0x2D)
#define SPI_SPSR (*(volatile u8 *)0x2E)
#define SPI_SPDR (*(volatile u8 *)0x2F)

/*SPSR BITS*/
#define SPIF_BIT 7
#define WCOL_BIT 6
#define SPI2X_BIT 0
/***/

#define MSTR 1
#define SLAVE 0
#define Rising_Falling 0
#define Falling_Rising 1

#define Sample_Setup 0
#define Setup_Sample 1

#define DOUBLE_SPEED_ON 0
#define DOUBLE_SPEED_OFF 0

#endif /* INCLUDE_MCAL_SPI_SPI_PRIVATE_H_ */
