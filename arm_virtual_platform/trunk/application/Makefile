#/**@file
# * @copyright
# *      This file is subject to the terms and conditions defined in
# *      file 'LICENSE.txt', which is part of this source code package.
# * @author
# *      Pham Hung Cuong (cuongph.et@gmail.com)
# * @date
# *      June 04, 2015
# *
# * @brief
# *      Application Makefile
# *
# -------------------------------------------------------------------------------
# Revision information:
# - $ProjectName::                                                              $
# - $ReleaseDate::                                                              $
# - $ReleaseVersion::                                                           $
# - $Revision:: 811                                                             $
# - $LastChangedBy:: cuongph8                                                   $
# - $LastChangedDate:: 2015-08-01 00:12:30 +0700 (Sat, 01 Aug 2015)             $
# - $FilePath::                                                                 $
# -------------------------------------------------------------------------------
#*/
SHELL = /bin/bash
APP ?= application

IMPERAS_HOME := $(shell getpath.exe "$(IMPERAS_HOME)")

# Build locally without using a VLNV library
NOVLNV = 1

OPTIMISATION        ?= -O2 -g -gdwarf-2
PKSPD_OPTIMISATION  ?= -O0 -g -gdwarf-2

# provide alternate build controls
MULT ?=
DEF  ?=

CROSS  ?= ARM_CORTEX_A8
#CROSS ?= ARM7

SRC    ?= $(APP).cpp

JC_PERIPHERAL_APP = peripherals/jc_reuse/timer_arm_sp804/Timer.cpp \
					peripherals/jc_reuse/uart_16450/Uart.cpp \
					peripherals/jc/func_demo/Demo.cpp

SRCINC ?= top_app.cpp \
		  $(JC_PERIPHERAL_APP)
					  
#ARM_TOOLCHAIN_VERSION = 4.9.1 
#ARM_TARGET = armv5te

ARM_TOOLCHAIN_VERSION = 4.8.3
ARM_TARGET = thumb2


INCLUDE_JC_REUSE  =
INCLUDE_JC_REUSE += -I$(IMPERAS_HOME)/ImperasLib/source
INCLUDE_JC  =
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/arm-none-eabi/include
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/arm-none-eabi/include/c++/$(ARM_TOOLCHAIN_VERSION)
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/arm-none-eabi/include/c++/$(ARM_TOOLCHAIN_VERSION)/arm-none-eabi
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/arm-none-eabi/include/c++/$(ARM_TOOLCHAIN_VERSION)/backward
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/include
INCLUDE_JC += -I${ARM_TOOLCHAIN_ROOT}/lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/include-fixed
INCLUDE_JC += -I${IMPERAS_HOME}/ImperasLib/source

LIB_STATIC_OBJ_JC  = 
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libg.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libstdc++.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libc.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libcs3hosted.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libsupc++.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libcs3unhosted.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libm.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libcs3arm.a
LIB_STATIC_OBJ_JC += ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libcs3.a


INCOBJ = $(patsubst %.cpp,%$(MULT).$(CROSS).o,$(SRCINC))
EXE    = $(patsubst %.cpp,%$(MULT).$(CROSS).elf,$(SRC))  # top_app.cpp -> top_app$(MULT).$(CROSS).elf

-include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS).makefile.include
ifeq ($($(CROSS)_CC),)
    IMPERAS_ERROR := $(error "Error : $(CROSS)_CC not set. Please check installation of toolchain for $(CROSS)")
endif

#-------------------------------------------------------------------------------

all: $(EXE)

#all: $(EXE) debug-makefile

#all: debug-makefile

#------------------------------------------------------------------------------
%$(MULT).$(CROSS).elf: %$(MULT).$(CROSS).o $(INCOBJ)
	@    echo -e "\n\n# Linking $(CROSS) $@"
	$(IMPERAS_LINK) -o $@ $^ $(IMPERAS_LDFLAGS) $(INCLUDE_JC_REUSE) $(INCLUDE_JC) $(LIB_STATIC_OBJ_JC) -lm

%$(MULT).$(CROSS).o: %.cpp
	@    echo -e "\n\n# Compiling $(CROSS) $<"
	$(IMPERAS_CC) -c -o $@ $< -D$(CROSS) $(DEF) $(OPTIMISATION) $(INCLUDE_JC_REUSE) $(INCLUDE_JC)

#------------------------------------------------------------------------------
%$(MULT).dbg.$(CROSS).elf: %$(MULT).dbg.$(CROSS).o $(INCOBJ)
	@    echo -e "\n\n# Linking $(CROSS) $@"
	$(IMPERAS_LINK) -o $@ $^ $(IMPERAS_LDFLAGS) $(INCLUDE_JC_REUSE) $(INCLUDE_JC) -lm

%$(MULT).dbg.$(CROSS).o: %.cpp
	@    echo -e "\n\n# Compiling $(CROSS) (Debug) $<"
	$(IMPERAS_CC) -c -o $@ $< -D$(CROSS) $(DEF) -O0 -g -gdwarf-2 $(INCLUDE_JC_REUSE) $(INCLUDE_JC)

#------------------------------------------------------------------------------
clean:
	rm -f *.$(CROSS).elf *.$(CROSS).o
	
#------------------------------------------------------------------------------
debug-makefile:
	@echo -e "\n\n# debug make file"
	@echo EXE: $(EXE)
	@echo -include: include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS).makefile.include
	ls -alh $(SRCINC)
	@echo CC: $(IMPERAS_CC) -c -o $@ $< -D$(CROSS) $(DEF) $(OPTIMISATION)
	@echo -e "\n IMPERAS_CC: $(IMPERAS_CC)"
	@echo -e "\n CROSS: $(CROSS)"
	@echo -e "\n DEF: $(DEF)"
	@echo -e "\n OPTIMISATION: $(OPTIMISATION)"
	@echo LINK: $(IMPERAS_LINK) -o $@ $^ $(IMPERAS_LDFLAGS) -lm
	@echo -e "\n IMPERAS_LINK: $(IMPERAS_LINK)"
	@echo -e "\n IMPERAS_LDFLAGS: $(IMPERAS_LDFLAGS)"
	@echo ImperasLib: $(IMPERAS_HOME)/ImperasLib/source
	@echo ls -alh ${ARM_TOOLCHAIN_ROOT}/bin/../lib/gcc/arm-none-eabi/$(ARM_TOOLCHAIN_VERSION)/../../../../arm-none-eabi/lib/$(ARM_TARGET)/libstdc++.a
	
#===============================================================================
# $FileName$
#===============================================================================
# vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
# vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
