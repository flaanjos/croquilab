################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/utils/FileDialog.cpp \
../src/main/c++/utils/filename.cpp \
../src/main/c++/utils/number_spliter.cpp 

OBJS += \
./src/main/c++/utils/FileDialog.o \
./src/main/c++/utils/filename.o \
./src/main/c++/utils/number_spliter.o 

CPP_DEPS += \
./src/main/c++/utils/FileDialog.d \
./src/main/c++/utils/filename.d \
./src/main/c++/utils/number_spliter.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/utils/%.o: ../src/main/c++/utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


