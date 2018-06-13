################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../File.cpp \
../Interpreter.cpp \
../Parser.cpp \
../main.cpp 

OBJS += \
./File.o \
./Interpreter.o \
./Parser.o \
./main.o 

CPP_DEPS += \
./File.d \
./Interpreter.d \
./Parser.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


