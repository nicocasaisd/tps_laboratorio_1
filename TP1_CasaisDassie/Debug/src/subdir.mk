################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1_CasaisDassie.c \
../src/tp1_lib.c 

C_DEPS += \
./src/TP1_CasaisDassie.d \
./src/tp1_lib.d 

OBJS += \
./src/TP1_CasaisDassie.o \
./src/tp1_lib.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP1_CasaisDassie.d ./src/TP1_CasaisDassie.o ./src/tp1_lib.d ./src/tp1_lib.o

.PHONY: clean-src

