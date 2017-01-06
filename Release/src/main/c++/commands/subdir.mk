################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/commands/AddObjectsToEndCommand.cpp \
../src/main/c++/commands/ChangeColorCommand.cpp \
../src/main/c++/commands/ChangeLineSizeCommand.cpp \
../src/main/c++/commands/ChangeLineTypeCommand.cpp \
../src/main/c++/commands/CreateCurvedPointCommand.cpp \
../src/main/c++/commands/CreateSegmentedPointCommand.cpp \
../src/main/c++/commands/DeleteObjectsCommand.cpp \
../src/main/c++/commands/EditCurvedPointCommand.cpp \
../src/main/c++/commands/EditListCommand.cpp \
../src/main/c++/commands/EditObjectsListCommand.cpp \
../src/main/c++/commands/EditPointScapeCommand.cpp \
../src/main/c++/commands/EditPositionCommand.cpp \
../src/main/c++/commands/EditScaleCommand.cpp \
../src/main/c++/commands/EditSegmentedPointCommand.cpp \
../src/main/c++/commands/EditTextCommand.cpp \
../src/main/c++/commands/EditWideSegmentedWidth.cpp \
../src/main/c++/commands/RemoveCurvedPointCommand.cpp \
../src/main/c++/commands/RemoveSegmentedPointCommand.cpp \
../src/main/c++/commands/commandStack.cpp 

OBJS += \
./src/main/c++/commands/AddObjectsToEndCommand.o \
./src/main/c++/commands/ChangeColorCommand.o \
./src/main/c++/commands/ChangeLineSizeCommand.o \
./src/main/c++/commands/ChangeLineTypeCommand.o \
./src/main/c++/commands/CreateCurvedPointCommand.o \
./src/main/c++/commands/CreateSegmentedPointCommand.o \
./src/main/c++/commands/DeleteObjectsCommand.o \
./src/main/c++/commands/EditCurvedPointCommand.o \
./src/main/c++/commands/EditListCommand.o \
./src/main/c++/commands/EditObjectsListCommand.o \
./src/main/c++/commands/EditPointScapeCommand.o \
./src/main/c++/commands/EditPositionCommand.o \
./src/main/c++/commands/EditScaleCommand.o \
./src/main/c++/commands/EditSegmentedPointCommand.o \
./src/main/c++/commands/EditTextCommand.o \
./src/main/c++/commands/EditWideSegmentedWidth.o \
./src/main/c++/commands/RemoveCurvedPointCommand.o \
./src/main/c++/commands/RemoveSegmentedPointCommand.o \
./src/main/c++/commands/commandStack.o 

CPP_DEPS += \
./src/main/c++/commands/AddObjectsToEndCommand.d \
./src/main/c++/commands/ChangeColorCommand.d \
./src/main/c++/commands/ChangeLineSizeCommand.d \
./src/main/c++/commands/ChangeLineTypeCommand.d \
./src/main/c++/commands/CreateCurvedPointCommand.d \
./src/main/c++/commands/CreateSegmentedPointCommand.d \
./src/main/c++/commands/DeleteObjectsCommand.d \
./src/main/c++/commands/EditCurvedPointCommand.d \
./src/main/c++/commands/EditListCommand.d \
./src/main/c++/commands/EditObjectsListCommand.d \
./src/main/c++/commands/EditPointScapeCommand.d \
./src/main/c++/commands/EditPositionCommand.d \
./src/main/c++/commands/EditScaleCommand.d \
./src/main/c++/commands/EditSegmentedPointCommand.d \
./src/main/c++/commands/EditTextCommand.d \
./src/main/c++/commands/EditWideSegmentedWidth.d \
./src/main/c++/commands/RemoveCurvedPointCommand.d \
./src/main/c++/commands/RemoveSegmentedPointCommand.d \
./src/main/c++/commands/commandStack.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/commands/%.o: ../src/main/c++/commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


