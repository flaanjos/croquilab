################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/c++/interface/additionalCursors.cpp \
../src/main/c++/interface/color_box.cpp \
../src/main/c++/interface/img_drop_down_list.cpp \
../src/main/c++/interface/img_drop_down_list2.cpp \
../src/main/c++/interface/location_window.cpp \
../src/main/c++/interface/main_color.cpp \
../src/main/c++/interface/main_window.cpp \
../src/main/c++/interface/main_window_background_menu.cpp \
../src/main/c++/interface/main_window_canvas.cpp \
../src/main/c++/interface/main_window_canvas2.cpp \
../src/main/c++/interface/main_window_color_panel.cpp \
../src/main/c++/interface/main_window_eidt_commands.cpp \
../src/main/c++/interface/main_window_line_panel.cpp \
../src/main/c++/interface/main_window_line_size_menu.cpp \
../src/main/c++/interface/main_window_line_type_menu.cpp \
../src/main/c++/interface/main_window_line_type_menu.h.cpp \
../src/main/c++/interface/main_window_object_panel.cpp \
../src/main/c++/interface/main_window_old.cpp \
../src/main/c++/interface/main_window_order_menu.cpp \
../src/main/c++/interface/main_window_zoom_panel.cpp \
../src/main/c++/interface/menu.cpp \
../src/main/c++/interface/route_window.cpp \
../src/main/c++/interface/scroll_color_bar.cpp 

OBJS += \
./src/main/c++/interface/additionalCursors.o \
./src/main/c++/interface/color_box.o \
./src/main/c++/interface/img_drop_down_list.o \
./src/main/c++/interface/img_drop_down_list2.o \
./src/main/c++/interface/location_window.o \
./src/main/c++/interface/main_color.o \
./src/main/c++/interface/main_window.o \
./src/main/c++/interface/main_window_background_menu.o \
./src/main/c++/interface/main_window_canvas.o \
./src/main/c++/interface/main_window_canvas2.o \
./src/main/c++/interface/main_window_color_panel.o \
./src/main/c++/interface/main_window_eidt_commands.o \
./src/main/c++/interface/main_window_line_panel.o \
./src/main/c++/interface/main_window_line_size_menu.o \
./src/main/c++/interface/main_window_line_type_menu.o \
./src/main/c++/interface/main_window_line_type_menu.h.o \
./src/main/c++/interface/main_window_object_panel.o \
./src/main/c++/interface/main_window_old.o \
./src/main/c++/interface/main_window_order_menu.o \
./src/main/c++/interface/main_window_zoom_panel.o \
./src/main/c++/interface/menu.o \
./src/main/c++/interface/route_window.o \
./src/main/c++/interface/scroll_color_bar.o 

CPP_DEPS += \
./src/main/c++/interface/additionalCursors.d \
./src/main/c++/interface/color_box.d \
./src/main/c++/interface/img_drop_down_list.d \
./src/main/c++/interface/img_drop_down_list2.d \
./src/main/c++/interface/location_window.d \
./src/main/c++/interface/main_color.d \
./src/main/c++/interface/main_window.d \
./src/main/c++/interface/main_window_background_menu.d \
./src/main/c++/interface/main_window_canvas.d \
./src/main/c++/interface/main_window_canvas2.d \
./src/main/c++/interface/main_window_color_panel.d \
./src/main/c++/interface/main_window_eidt_commands.d \
./src/main/c++/interface/main_window_line_panel.d \
./src/main/c++/interface/main_window_line_size_menu.d \
./src/main/c++/interface/main_window_line_type_menu.d \
./src/main/c++/interface/main_window_line_type_menu.h.d \
./src/main/c++/interface/main_window_object_panel.d \
./src/main/c++/interface/main_window_old.d \
./src/main/c++/interface/main_window_order_menu.d \
./src/main/c++/interface/main_window_zoom_panel.d \
./src/main/c++/interface/menu.d \
./src/main/c++/interface/route_window.d \
./src/main/c++/interface/scroll_color_bar.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/c++/interface/%.o: ../src/main/c++/interface/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


