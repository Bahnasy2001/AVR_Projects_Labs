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
H_Bridge_Test.lss \

FLASH_IMAGE += \
H_Bridge_Test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: H_Bridge_Test.elf secondary-outputs

# Tool invocations
H_Bridge_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,H_Bridge_Test.map -mmcu=atmega32 -o "H_Bridge_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

H_Bridge_Test.lss: H_Bridge_Test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S H_Bridge_Test.elf  >"H_Bridge_Test.lss"
	@echo 'Finished building: $@'
	@echo ' '

H_Bridge_Test.hex: H_Bridge_Test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex H_Bridge_Test.elf  "H_Bridge_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: H_Bridge_Test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 H_Bridge_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) H_Bridge_Test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
