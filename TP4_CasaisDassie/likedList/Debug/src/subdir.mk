################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/main.c \
../src/micro.c 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/main.d \
./src/micro.d 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/main.o \
./src/micro.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Controller.d ./src/Controller.o ./src/LinkedList.d ./src/LinkedList.o ./src/main.d ./src/main.o ./src/micro.d ./src/micro.o

.PHONY: clean-src

