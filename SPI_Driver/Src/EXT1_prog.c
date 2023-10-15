/*
 * EXT1_prog.c
 *
 *  Created on: Jul 9, 2023
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
#include <util/delay.h>
#define F_CPU 8000000UL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SENSE_MODE_MASK 0b11

#define EXTI0_SENSE_B1 0
#define EXTI1_SENSE_B1 2
#define EXTI2_SENSE_B1 6

#define NULL 0
void (*EXTI0_callback)(void) = NULL; // to use it with if
void (*EXTI1_callback)(void) = NULL; // to use it with if
void (*EXTI2_callback)(void) = NULL; // to use it with if

void MEXTI_voidConfig(u8 A_u8EXTI, u8 A_u8SenseMode)
{
    if (A_u8SenseMode >= 4)
    {
        return;
    }
    switch (A_u8EXTI)
    {

    case EXTI0: // bits 0,1 clear  ,,MASKING
    {
        MCUCR &= !(SENSE_MODE_MASK << EXTI0_SENSE_B1);
        MCUCR |= (A_u8SenseMode << EXTI0_SENSE_B1);
        break;
    }
    case EXTI1: // bits 2,3 clear
    {
        MCUCR &= !(SENSE_MODE_MASK << EXTI1_SENSE_B1);
        MCUCR |= (A_u8SenseMode << EXTI1_SENSE_B1);
        break;
    }
    case EXTI2:
    {
        switch (A_u8SenseMode)
        {
        case FALLING_EDGE:
            CLR_BIT(MCUCSR, EXTI2_SENSE_B1);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR, EXTI2_SENSE_B1);
            break;
        }
        break;
    }
    default:
        break;
    }
}
/*
#define EXTI0_ENABLE_BIT 6 // BIT 6
#define EXTI1_ENABLE_BIT 7 // BIT 7
#define EXTI2_ENABLE_BIT 5 // BIT 5
*/

void MEXTI_voidEnable(u8 A_u8EXTI)
{
    switch (A_u8EXTI)
    {
    case EXTI0:
        SET_BIT(GICR, EXTI0_ENABLE_BIT);
        break;
    case EXTI1:
        SET_BIT(GICR, EXTI1_ENABLE_BIT);
        break;
    case EXTI2:
        SET_BIT(GICR, EXTI2_ENABLE_BIT);
        break;
    default:
        break;
    }
}
void MEXTI_voidDisable(u8 A_u8EXTI)
{
    switch (A_u8EXTI)
    {
    case EXTI0:
        CLR_BIT(GICR, EXTI0_ENABLE_BIT);
        break;
    case EXTI1:
        CLR_BIT(GICR, EXTI1_ENABLE_BIT);
        break;
    case EXTI2:
        CLR_BIT(GICR, EXTI2_ENABLE_BIT);
        break;
    default:
        break;
    }
}

/*
#define EXTI0_FLAG_BIT 6 // BIT 6
#define EXTI1_FLAG_BIT 7 // BIT 7
#define EXTI2_FLAG_BIT 5 // BIT 5
*/
void MEXTI_voidClearFlag(u8 A_u8EXTI)
{

    switch (A_u8EXTI)
    {
    case EXTI0:
        SET_BIT(GICR, EXTI0_FLAG_BIT);
        break;
    case EXTI1:
        SET_BIT(GICR, EXTI1_FLAG_BIT);
        break;
    case EXTI2:
        SET_BIT(GICR, EXTI2_FLAG_BIT);
        break;
    default:
        break;
    }
}

void MEXTI_voidsetCallBack(u8 A_u8EXTI, void *ptrtofunc(void))
{
    switch (A_u8EXTI)
    {
    case EXTI0:
        EXTI0_callback = ptrtofunc;
        break;
    case EXTI1:
        EXTI1_callback = ptrtofunc;
        break;
    case EXTI2:
        EXTI2_callback = ptrtofunc;
        break;
    default:
        break;
    }
    if (ptrtofunc != NULL)
    {
        EXTI0_callback = ptrtofunc; // address of ptrfun(ToggleLEd) now moved to EXTI0_callback
    }
}

void __vector_1(void) __attribute__((signal)); // ISR call it when interrupt happens, __attribute for linker to know that processor calls it
void __vector_1(void)
{
    if (EXTI0_callback != NULL)
        EXTI0_callback();
}

void __vector_2(void) __attribute__((signal)); // ISR call it when interrupt happens, __attribute for linker to know that processor calls it
void __vector_2(void)
{
    if (EXTI1_callback != NULL)
        EXTI1_callback();
}

void __vector_3(void) __attribute__((signal)); // ISR call it when interrupt happens, __attribute for linker to know that processor calls it
void __vector_3(void)
{
    if (EXTI2_callback != NULL)
        EXTI2_callback();
}
