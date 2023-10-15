################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/EXT1_prog.c \
../Src/GI_program.c \
../Src/SPI_program.c \
../Src/main_slave.c 

OBJS += \
./Src/DIO_program.o \
./Src/EXT1_prog.o \
./Src/GI_program.o \
./Src/SPI_program.o \
./Src/main_slave.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/EXT1_prog.d \
./Src/GI_program.d \
./Src/SPI_program.d \
./Src/main_slave.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


