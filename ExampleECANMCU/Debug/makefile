################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./DSP2833x_ADC_cal.obj" \
"./DSP2833x_CodeStartBranch.obj" \
"./DSP2833x_DefaultIsr.obj" \
"./DSP2833x_ECan.obj" \
"./DSP2833x_GlobalVariableDefs.obj" \
"./DSP2833x_PieCtrl.obj" \
"./DSP2833x_PieVect.obj" \
"./DSP2833x_SysCtrl.obj" \
"./DSP2833x_usDelay.obj" \
"./ECan_TX_RX.obj" \
"./cpu_timer0.obj" \
"./main.obj" \
"../28335_RAM_lnk.cmd" \
"../DSP2833x_Headers_nonBIOS.cmd" \
"../lib/SFO_TI_Build.lib" \
"../lib/SFO_TI_Build_V5.lib" \
"../lib/SFO_TI_Build_V5B.lib" \
"../lib/SFO_TI_Build_V5B_fpu.lib" \
"../lib/SFO_TI_Build_V5_fpu.lib" \
"../lib/SFO_TI_Build_fpu.lib" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include lib/subdir_vars.mk
-include subdir_rules.mk
-include lib/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Example_2833xECanA_to_B_Xmit.out \

EXE_OUTPUTS__QUOTED += \
"Example_2833xECanA_to_B_Xmit.out" \

BIN_OUTPUTS += \
Example_2833xECanA_to_B_Xmit.hex \

BIN_OUTPUTS__QUOTED += \
"Example_2833xECanA_to_B_Xmit.hex" \


# All Target
all: Example_2833xECanA_to_B_Xmit.out

# Tool invocations
Example_2833xECanA_to_B_Xmit.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --issue_remarks --diag_warning=225 --verbose_diagnostics --output_all_syms --cdebug_asm_data -z -m"Example_2833xECanA_to_B_Xmit.map" --stack_size=0x380 --warn_sections -i"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/lib" -i"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" -i"C:/Users/ASUS/workspace_v6_1_3/ExampleECANMCU" -i"C:/Users/ASUS/workspace_v6_1_3/ExampleECANMCU/lib" --priority --reread_libs --verbose_diagnostics --issue_remarks --xml_link_info="Example_2833xECanA_to_B_Xmit_linkInfo.xml" --rom_model -o "Example_2833xECanA_to_B_Xmit.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Example_2833xECanA_to_B_Xmit.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/hex2000"  -o "Example_2833xECanA_to_B_Xmit.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "DSP2833x_DefaultIsr.d" "DSP2833x_ECan.d" "DSP2833x_GlobalVariableDefs.d" "DSP2833x_PieCtrl.d" "DSP2833x_PieVect.d" "DSP2833x_SysCtrl.d" "ECan_TX_RX.d" "cpu_timer0.d" "main.d" 
	-$(RM) "DSP2833x_ADC_cal.obj" "DSP2833x_CodeStartBranch.obj" "DSP2833x_DefaultIsr.obj" "DSP2833x_ECan.obj" "DSP2833x_GlobalVariableDefs.obj" "DSP2833x_PieCtrl.obj" "DSP2833x_PieVect.obj" "DSP2833x_SysCtrl.obj" "DSP2833x_usDelay.obj" "ECan_TX_RX.obj" "cpu_timer0.obj" "main.obj" 
	-$(RM) "DSP2833x_ADC_cal.d" "DSP2833x_CodeStartBranch.d" "DSP2833x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

