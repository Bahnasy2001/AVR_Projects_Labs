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
Moving_Name.lss \

FLASH_IMAGE += \
Moving_Name.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Moving_Name.elf secondary-outputs

# Tool invocations
Moving_Name.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Moving_Name.map -mmcu=atmega32 -o "Moving_Name.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Moving_Name.lss: Moving_Name.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Moving_Name.elf  >"Moving_Name.lss"
	@echo 'Finished building: $@'
	@echo ' '

Moving_Name.hex: Moving_Name.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Moving_Name.elf  "Moving_Name.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Moving_Name.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Moving_Name.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Moving_Name.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
