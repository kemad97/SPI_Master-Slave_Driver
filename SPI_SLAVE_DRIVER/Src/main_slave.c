/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_configuration.h"

#include "../include/MCAL/EXT1/EXT1_interface.h"
#include "../include/MCAL/EXT1/EXT1_private.h"
#include "../include/MCAL/EXT1/EXT1_config.h"

#include "../Include/MCAL/SPI/SPI_interface.h"
#include "../Include/MCAL/SPI/SPI_private.h"
#include "../Include/MCAL/SPI/SPI_config.h"

#define F_CPU 8000000UL


#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111

#define BUTTON_PIN   PORTD_PIN2_VALUE // Change this to the appropriate pin where your button is connected
static u8 displayValue = 1;

void toggle_led();
void SevenSeg_disp(u8 A_u8Num);



#if 1
u8 flag=0;
int main(void)
{
    u8 counterdisp = 0;
    MDIO_voidInit();
    MSPI_voidInit();
    MGI_void_Enable_Global_INT();
    MEXTI_voidConfig(EXTI0, RISING_EDGE); // Configure EXTI0 to trigger on button press
    MEXTI_voidEnable(EXTI0);
    u8 local_u8_DATA;
    while (1)
    {
        MDIO_voidSetPinValue(PORTA, PIN0, PIN_LOW); // ss``
        local_u8_DATA = MSPI_u8_Getdata(7);

        MDIO_voidSetPinValue(PORTA, PIN0, PIN_HIGH); // ss``

        if (local_u8_DATA == 5 )
        {
        	SevenSeg_disp(displayValue);
       	    local_u8_DATA = 0;
            toggle_led();
            _delay_ms(200);
            toggle_led();
        }
    }
}
#endif
#if 0 // test toggle
int main(void)
{

    MDIO_voidInit();
    MSPI_voidInit();
    while (1)
    {
        toggle_led();
        _delay_ms(10);
    }
}
#endif
//////////////////////////////////////////////
void toggle_led()
{
    static u8 local_u8_flag = 0;
    if (local_u8_flag == 0)
    {
        MDIO_voidSetPinValue(PORTD, PIN0, PIN_HIGH);
        local_u8_flag = 1;
    }
    else
    {
        MDIO_voidSetPinValue(PORTD, PIN0, PIN_LOW);
        local_u8_flag = 0;
    }
}

void SevenSeg_disp(u8 A_u8Num)
{
    u8 portCValue = 0;  // Initialize a variable to hold the new PORTC value


    MDIO_voidSetPinValue(PORTD, PIN2, PIN_LOW);
    MDIO_voidSetPinValue(PORTD, PIN2, PIN_HIGH);

    // Check if the button is pressed (EXTI0 is triggered)
    if (1/*A_u8Num == EXTI0*/)
    {
        // Toggle between displaying numbers

        // Reset to ZERO if it exceeds NINE
        if (displayValue > 9)
        {
            displayValue = 0;
        }

        // Set the appropriate bits for the 7-segment display
        switch (displayValue)
        {
        case 0:
            portCValue = ZERO;
            break;
        case 1:
            portCValue = ONE;
            break;
        case 2:
            portCValue = TWO;
            break;
        case 3:
            portCValue = THREE;
            break;
        case 4:
            portCValue = FOUR;
            break;
        case 5:
            portCValue = FIVE;
            break;
        case 6:
            portCValue = SIX;
            break;
        case 7:
            portCValue = SEVEN;
            break;
        case 8:
            portCValue = EIGHT;
            break;
        case 9:
            portCValue = NINE;
            break;
        }

        // Update PORTC with the new value
//        PORTC_REG = portCValue;
        MDIO_voidSetPortValue(PORTC, portCValue);
        displayValue++;
    }
}
