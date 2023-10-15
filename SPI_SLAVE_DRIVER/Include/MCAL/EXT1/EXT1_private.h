/*
 * EXT1_private.h
 *
 *  Created on: Jul 9, 2023
 *      Author: Kerolos
 */

#ifndef INCLUDE_MCAL_EXT1_EXT1_PRIVATE_H_
#define INCLUDE_MCAL_EXT1_EXT1_PRIVATE_H_

#define MCUCR (*(volatile u8 *)0x55)

#define MCUCSR (*(volatile u8 *)0x54)

#define GICR (*(volatile u8 *)0x5B)

#define GIFR (*(volatile u8 *)0x5A)

#define EXTI0_ENABLE_BIT 6 // BIT 6
#define EXTI1_ENABLE_BIT 7 // BIT 7
#define EXTI2_ENABLE_BIT 5 // BIT 5

#define EXTI0_FLAG_BIT 6 // BIT 6
#define EXTI1_FLAG_BIT 7 // BIT 7
#define EXTI2_FLAG_BIT 5 // BIT 5
#endif                   /* INCLUDE_MCAL_EXT1_EXT1_PRIVATE_H_ */
