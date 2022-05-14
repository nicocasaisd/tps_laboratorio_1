################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayPassenger.c \
../src/TP2_CasaisDassie.c \
../src/my_lib.c \
../src/tp2_lib.c 

C_DEPS += \
./src/ArrayPassenger.d \
./src/TP2_CasaisDassie.d \
./src/my_lib.d \
./src/tp2_lib.d 

OBJS += \
./src/ArrayPassenger.o \
./src/TP2_CasaisDassie.o \
./src/my_lib.o \
./src/tp2_lib.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/TP2_CasaisDassie.d ./src/TP2_CasaisDassie.o ./src/my_lib.d ./src/my_lib.o ./src/tp2_lib.d ./src/tp2_lib.o

.PHONY: clean-src

