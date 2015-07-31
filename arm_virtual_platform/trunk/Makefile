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
# *      Top makefile that invokes application and platform makefiles, and
# *      execute the simulation
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
APP   ?= top_app

CROSS ?= ARM_CORTEX_A8
ifndef CROSS
  CROSS := $(error "CROSS must be defined for ARM CPU name")
endif

ifeq ($(CROSS),ARM7)
	ARM_VARIANT = "ARM7TDMI" # ARM7EJ-S ARM720T
endif
ifeq ($(CROSS),ARM_CORTEX_A9)
	ARM_VARIANT = "Cortex-A9UP"
endif
ifeq ($(CROSS),ARM_CORTEX_A8)
	ARM_VARIANT = "Cortex-A8"
endif
#===============================================================================


all: run-simulation

debug: run-simulation-debug


#### Compile each source file ####

build-application :
	@ echo -e "\n\n Build the application"
	@ $(MAKE) -C ./application/ -f Makefile CROSS="$(CROSS)"

build-platform :
	@ echo -e  "\n\n Build the platform"
	@ $(MAKE) -C ./platform/ -f Makefile

build-platform-debug :
	@ echo -e  "\n\n Build the platform"
	@ $(MAKE) -C ./platform/ -f Makefile platform-debug




run-simulation: build-application build-platform clean-simulation
	@ echo -e "\n\n Run simulation"
	@ mkdir -p ./sim
	cd ./sim \
	; ../platform/main.Linux32.exe  \
				../application/dbg/application.elf \
				$(ARM_VARIANT) \
	| tee sim_log \
	; cd ..

run-simulation-debug: build-application build-platform-debug clean-simulation
	@ echo -e "\n\n Run simulation"
	cd ./sim \
	; ../platform/main.Linux32.exe  \
				../application/dbg/application.elf \
				$(ARM_VARIANT) \
	| tee debug_log \
	; cd ..


#### Clean up ####
clean: clean-simulation
	@ echo -e "\n\n Clean-up the project"
	@ echo -e "\n\n Clean the application"
	@ $(MAKE) -C ./application/ -f Makefile clean CROSS="$(CROSS)"
	@ echo -e "\n\n Clean the platform"
	@ $(MAKE) -C ./platform/ -f Makefile  clean

clean-simulation:
	@ echo -e "\n\n clean simulation log & result"
	@ rm -rf ./sim/*.vcd ./sim/*.log

#### Debug makefile ####
debug:
	@echo -e "\n\nDebug makefile"

#===============================================================================
# $FileName$
#===============================================================================
# vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
# vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:

