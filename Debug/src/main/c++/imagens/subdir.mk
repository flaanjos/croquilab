################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/imagens/object_callbacks.cpp 

OBJS += \
./src/main/c++/imagens/object_callbacks.o 

CPP_DEPS += \
./src/main/c++/imagens/object_callbacks.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/imagens/%.o: ../src/main/c++/imagens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/flavia/programacao/cpp_libs/cd/include -I/home/flavia/programacao/cpp_libs/im/include -I/home/flavia/programacao/cpp_libs/iup/include -I/home/flavia/croquilab/croquiLab/src -I/home/flavia/croquilab/croquiLab/src/main/c++/buttons -I/home/flavia/croquilab/croquiLab/src/main/c++/commands -I/home/flavia/croquilab/croquiLab/src/main/c++/geom -I/home/flavia/croquilab/croquiLab/src/main/c++/images -I/home/flavia/croquilab/croquiLab/src/main/c++/interface -I/home/flavia/croquilab/croquiLab/src/main/c++/obj -I/home/flavia/croquilab/croquiLab/src/main/c++/utils -I/home/flavia/croquilab/croquiLab/src/main/c++/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


