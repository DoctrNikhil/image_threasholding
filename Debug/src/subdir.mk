################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/image_thresholding.c \
../src/threashold.c \
../src/timeCheck.c 

C_DEPS += \
./src/image_thresholding.d \
./src/threashold.d \
./src/timeCheck.d 

OBJS += \
./src/image_thresholding.o \
./src/threashold.o \
./src/timeCheck.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O0 -g3 -Wall -c  -mfpu=neon -march=armv8-a -marm -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/image_thresholding.d ./src/image_thresholding.o ./src/threashold.d ./src/threashold.o ./src/timeCheck.d ./src/timeCheck.o

.PHONY: clean-src

