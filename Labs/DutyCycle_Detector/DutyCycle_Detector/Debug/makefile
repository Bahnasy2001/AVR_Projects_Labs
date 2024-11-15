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
DutyCycle_Detector.lss \

FLASH_IMAGE += \
DutyCycle_Detector.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DutyCycle_Detector.elf secondary-outputs

# Tool invocations
DutyCycle_Detector.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DutyCycle_Detector.map -mmcu=atmega32 -o "DutyCycle_Detector.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DutyCycle_Detector.lss: DutyCycle_Detector.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DutyCycle_Detector.elf  >"DutyCycle_Detector.lss"
	@echo 'Finished building: $@'
	@echo ' '

DutyCycle_Detector.hex: DutyCycle_Detector.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DutyCycle_Detector.elf  "DutyCycle_Detector.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DutyCycle_Detector.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DutyCycle_Detector.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DutyCycle_Detector.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
