################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Boruvka.cpp \
../GraphGen.cpp \
../Graphs.cpp \
../Kruskal.cpp \
../Main.cpp \
../Prim.cpp 

OBJS += \
./Boruvka.o \
./GraphGen.o \
./Graphs.o \
./Kruskal.o \
./Main.o \
./Prim.o 

CPP_DEPS += \
./Boruvka.d \
./GraphGen.d \
./Graphs.d \
./Kruskal.d \
./Main.d \
./Prim.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Main.o: ../Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"Main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


