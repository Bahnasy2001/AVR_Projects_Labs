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
SSD_Rotation.lss \

FLASH_IMAGE += \
SSD_Rotation.hex \

EEPROM_IMAGE += \
SSD_Rotation.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SSD_Rotation.elf secondary-outputs

# Tool invocations
SSD_Rotation.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SSD_Rotation.map -mmcu=atmega32 -o "SSD_Rotation.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SSD_Rotation.lss: SSD_Rotation.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SSD_Rotation.elf  >"SSD_Rotation.lss"
	@echo 'Finished building: $@'
	@echo ' '

SSD_Rotation.hex: SSD_Rotation.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SSD_Rotation.elf  "SSD_Rotation.hex"
	@echo 'Finished building: $@'
	@echo ' '

SSD_Rotation.eep: SSD_Rotation.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SSD_Rotation.elf  "SSD_Rotation.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SSD_Rotation.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SSD_Rotation.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SSD_Rotation.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
