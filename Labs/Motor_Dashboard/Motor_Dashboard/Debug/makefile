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
Motor_Dashboard.lss \

FLASH_IMAGE += \
Motor_Dashboard.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Motor_Dashboard.elf secondary-outputs

# Tool invocations
Motor_Dashboard.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Motor_Dashboard.map -mmcu=atmega32 -o "Motor_Dashboard.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Motor_Dashboard.lss: Motor_Dashboard.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Motor_Dashboard.elf  >"Motor_Dashboard.lss"
	@echo 'Finished building: $@'
	@echo ' '

Motor_Dashboard.hex: Motor_Dashboard.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Motor_Dashboard.elf  "Motor_Dashboard.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Motor_Dashboard.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Motor_Dashboard.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Motor_Dashboard.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
