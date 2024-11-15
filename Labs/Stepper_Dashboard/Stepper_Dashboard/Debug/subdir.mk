################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../Dashboard.c \
../H_Bridge.c \
../KPD_program.c \
../LCD_program.c \
../Login_System.c \
../STEPPER_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./Dashboard.o \
./H_Bridge.o \
./KPD_program.o \
./LCD_program.o \
./Login_System.o \
./STEPPER_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./Dashboard.d \
./H_Bridge.d \
./KPD_program.d \
./LCD_program.d \
./Login_System.d \
./STEPPER_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


