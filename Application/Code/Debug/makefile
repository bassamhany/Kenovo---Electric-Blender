################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SWE_APP.lss \

FLASH_IMAGE += \
SWE_APP.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: SWE_APP.elf secondary-outputs

# Tool invocations
SWE_APP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SWE_APP.map -mmcu=atmega32 -o "SWE_APP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SWE_APP.lss: SWE_APP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SWE_APP.elf  >"SWE_APP.lss"
	@echo 'Finished building: $@'
	@echo ' '

SWE_APP.hex: SWE_APP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SWE_APP.elf  "SWE_APP.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SWE_APP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SWE_APP.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: SWE_APP.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:SWE_APP.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SWE_APP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
