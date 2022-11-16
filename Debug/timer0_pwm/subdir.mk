################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../timer0_pwm/timer0_pwm.c 

OBJS += \
./timer0_pwm/timer0_pwm.o 

C_DEPS += \
./timer0_pwm/timer0_pwm.d 


# Each subdirectory must supply rules for building sources it contributes
timer0_pwm/%.o: ../timer0_pwm/%.c timer0_pwm/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


