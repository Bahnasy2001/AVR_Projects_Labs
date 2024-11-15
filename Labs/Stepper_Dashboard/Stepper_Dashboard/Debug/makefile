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
Stepper_Dashboard.lss \

FLASH_IMAGE += \
Stepper_Dashboard.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Stepper_Dashboard.elf secondary-outputs

# Tool invocations
Stepper_Dashboard.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Stepper_Dashboard.map -mmcu=atmega32 -o "Stepper_Dashboard.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Stepper_Dashboard.lss: Stepper_Dashboard.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Stepper_Dashboard.elf  >"Stepper_Dashboard.lss"
	@echo 'Finished building: $@'
	@echo ' '

Stepper_Dashboard.hex: Stepper_Dashboard.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Stepper_Dashboard.elf  "Stepper_Dashboard.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Stepper_Dashboard.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Stepper_Dashboard.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Stepper_Dashboard.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
