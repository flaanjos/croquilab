################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/ProjectSaver.cpp \
../src/main/c++/builder.cpp \
../src/main/c++/colorBox.cpp \
../src/main/c++/croquiLab.cpp \
../src/main/c++/geometrias.cpp \
../src/main/c++/main.cpp \
../src/main/c++/main2.cpp \
../src/main/c++/page.cpp \
../src/main/c++/palm_tree_points.cpp \
../src/main/c++/project.cpp \
../src/main/c++/projectLoader.cpp \
../src/main/c++/projectLoader2.cpp \
../src/main/c++/route.cpp \
../src/main/c++/topo_editor.cpp 

OBJS += \
./src/main/c++/ProjectSaver.o \
./src/main/c++/builder.o \
./src/main/c++/colorBox.o \
./src/main/c++/croquiLab.o \
./src/main/c++/geometrias.o \
./src/main/c++/main.o \
./src/main/c++/main2.o \
./src/main/c++/page.o \
./src/main/c++/palm_tree_points.o \
./src/main/c++/project.o \
./src/main/c++/projectLoader.o \
./src/main/c++/projectLoader2.o \
./src/main/c++/route.o \
./src/main/c++/topo_editor.o 

CPP_DEPS += \
./src/main/c++/ProjectSaver.d \
./src/main/c++/builder.d \
./src/main/c++/colorBox.d \
./src/main/c++/croquiLab.d \
./src/main/c++/geometrias.d \
./src/main/c++/main.d \
./src/main/c++/main2.d \
./src/main/c++/page.d \
./src/main/c++/palm_tree_points.d \
./src/main/c++/project.d \
./src/main/c++/projectLoader.d \
./src/main/c++/projectLoader2.d \
./src/main/c++/route.d \
./src/main/c++/topo_editor.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/%.o: ../src/main/c++/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


