/*
 * GI_program.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Kerolos
 */
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../include/MCAL/EXT1/EXT1_interface.h"
#include "../include/MCAL/EXT1/EXT1_private.h"
#include "../include/MCAL/EXT1/EXT1_config.h"

#include "../include/MCAL/GI/GI_interface.h"
#include "../include/MCAL/GI/GI_private.h"
#include "../include/MCAL/GI/GI_config.h"

#include <util/delay.h>
#define F_CPU 8000000UL

#define NULL 0
void (*EXTI_callback)(void) = NULL;
void MGI_void_Enable_Global_INT(void)
{
    SET_BIT(SREG, GLOBAL_INT_ENABLE_BIT);
}

void MGI_void_Disable_Global_INT(void)
{
    CLR_BIT(SREG, GLOBAL_INT_ENABLE_BIT);
}
