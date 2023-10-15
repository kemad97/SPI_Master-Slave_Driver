/*
 * GI_private.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Kerolos
 */

#ifndef INCLUDE_MCAL_GI_GI_PRIVATE_H_
#define INCLUDE_MCAL_GI_GI_PRIVATE_H_

#define SREG (*(volatile u8 *)0x5F) // casts the memory address 0x5f as a pointer to volatile u8
                                    // then dereference value stored at it
#define GLOBAL_INT_ENABLE_BIT 7
#endif /* INCLUDE_MCAL_GI_GI_PRIVATE_H_ */
