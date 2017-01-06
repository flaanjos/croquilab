################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/geom/bezier.cpp \
../src/main/c++/geom/ellipse.cpp \
../src/main/c++/geom/point2d.cpp \
../src/main/c++/geom/polygon.cpp \
../src/main/c++/geom/rectangle.cpp \
../src/main/c++/geom/segment.cpp 

OBJS += \
./src/main/c++/geom/bezier.o \
./src/main/c++/geom/ellipse.o \
./src/main/c++/geom/point2d.o \
./src/main/c++/geom/polygon.o \
./src/main/c++/geom/rectangle.o \
./src/main/c++/geom/segment.o 

CPP_DEPS += \
./src/main/c++/geom/bezier.d \
./src/main/c++/geom/ellipse.d \
./src/main/c++/geom/point2d.d \
./src/main/c++/geom/polygon.d \
./src/main/c++/geom/rectangle.d \
./src/main/c++/geom/segment.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/geom/%.o: ../src/main/c++/geom/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


