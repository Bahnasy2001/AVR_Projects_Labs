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
ServoPot_Control.lss \

FLASH_IMAGE += \
ServoPot_Control.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ServoPot_Control.elf secondary-outputs

# Tool invocations
ServoPot_Control.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ServoPot_Control.map -mmcu=atmega32 -o "ServoPot_Control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ServoPot_Control.lss: ServoPot_Control.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ServoPot_Control.elf  >"ServoPot_Control.lss"
	@echo 'Finished building: $@'
	@echo ' '

ServoPot_Control.hex: ServoPot_Control.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ServoPot_Control.elf  "ServoPot_Control.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ServoPot_Control.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ServoPot_Control.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ServoPot_Control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
