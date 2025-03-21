################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
/home/alisoukarieh/Documents/ProjetCodesign/baremetal/helloworld/src/helloworld.c \
/home/alisoukarieh/Documents/ProjetCodesign/baremetal/helloworld/src/platform.c 

OBJS += \
./src/helloworld.o \
./src/platform.o 

C_DEPS += \
./src/helloworld.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/helloworld.o: /home/alisoukarieh/Documents/ProjetCodesign/baremetal/helloworld/src/helloworld.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsct/workspace/pfm_baremetal/export/pfm_baremetal/sw/pfm_baremetal/standalone_domain/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/platform.o: /home/alisoukarieh/Documents/ProjetCodesign/baremetal/helloworld/src/platform.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsct/workspace/pfm_baremetal/export/pfm_baremetal/sw/pfm_baremetal/standalone_domain/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


