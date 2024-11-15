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
Measure_POT_With_LCD_Motor.lss \

FLASH_IMAGE += \
Measure_POT_With_LCD_Motor.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Measure_POT_With_LCD_Motor.elf secondary-outputs

# Tool invocations
Measure_POT_With_LCD_Motor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Measure_POT_With_LCD_Motor.map -mmcu=atmega32 -o "Measure_POT_With_LCD_Motor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Measure_POT_With_LCD_Motor.lss: Measure_POT_With_LCD_Motor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Measure_POT_With_LCD_Motor.elf  >"Measure_POT_With_LCD_Motor.lss"
	@echo 'Finished building: $@'
	@echo ' '

Measure_POT_With_LCD_Motor.hex: Measure_POT_With_LCD_Motor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Measure_POT_With_LCD_Motor.elf  "Measure_POT_With_LCD_Motor.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Measure_POT_With_LCD_Motor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Measure_POT_With_LCD_Motor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Measure_POT_With_LCD_Motor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
