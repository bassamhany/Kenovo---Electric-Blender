################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DCMotor_prog.c \
../DIO_prog.c \
../Main.c \
../PWM_prog.c \
../TACTILE_prog.c 

OBJS += \
./DCMotor_prog.o \
./DIO_prog.o \
./Main.o \
./PWM_prog.o \
./TACTILE_prog.o 

C_DEPS += \
./DCMotor_prog.d \
./DIO_prog.d \
./Main.d \
./PWM_prog.d \
./TACTILE_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

