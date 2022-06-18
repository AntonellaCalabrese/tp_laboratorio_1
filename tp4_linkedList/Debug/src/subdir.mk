################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Passenger.c \
../src/main.c \
../src/parser.c \
../src/utn.c 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Passenger.d \
./src/main.d \
./src/parser.d \
./src/utn.d 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Passenger.o \
./src/main.o \
./src/parser.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Controller.d ./src/Controller.o ./src/LinkedList.d ./src/LinkedList.o ./src/Passenger.d ./src/Passenger.o ./src/main.d ./src/main.o ./src/parser.d ./src/parser.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

