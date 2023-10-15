/*
 * SPI_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Kerolos
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

void MSPI_voidInit(void);
void SPI_voidSetCallback(void (*copy_ptrFunc)(void)); // receive from main any func and put it to interrupt
u8 MSPI_u8_Getdata(u8 local_u8Data);

/*DO FUNC FOR DOUBLE SPEED*/

#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
