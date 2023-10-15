/*
 * SPI_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Kerolos
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../Include/MCAL/SPI/SPI_interface.h"
#include "../Include/MCAL/SPI/SPI_private.h"
#include "../Include/MCAL/SPI/SPI_config.h"

static void (*funcptr)(void) = NULL;

void MSPI_voidInit(void)
{
    SPI_SPCR = CONC_BIT(SPI_INTERRUPT_ENABLE, SPI_ENABLE, DATA_ORDER, MSTR_SLAVE_SELECT, CLOCK_POLARITY, CLOCK_PHASE, SPR1, SPR0);
}
u8 MSPI_u8_Getdata(u8 local_u8Data)
{
    SPI_SPDR = local_u8Data;
    while (GET_BIT(SPI_SPSR, SPIF_BIT) == 0)
        ; // When a serial transfer is complete, the SPIF Flag is set.
    return SPI_SPDR;
}

void SPI_voidSetCallback(void (*copy_ptrFunc)(void)) // receive from main any func and put it to interrupt
{
    if (copy_ptrFunc != NULL)
    {
        funcptr = copy_ptrFunc;
    }
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
    if (funcptr != NULL)
    {
        funcptr();
    }
}
