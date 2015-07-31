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
# *      Platform Makefile
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

ARM_VIRTUAL_PLATFORM := platform_top.cpp

SRC =   main.cpp \
        $(ARM_VIRTUAL_PLATFORM)

all: platform

platform:
	$(MAKE) -f ${IMPERAS_HOME}/ImperasLib/buildutils/Makefile.TLM.platform \
								SRC="$(SRC)" \
								CFLAGS="-I$(SCML_HOME)/include" \
								LDFLAGS="-L$(SCML_HOME)/lib-linux -lModelingObjects  -lscml_clock -lscml2 -lscml2_logging -lscml2_testing -lscml2_testing_systemc_main "

platform-debug:
	$(MAKE) -f ${IMPERAS_HOME}/ImperasLib/buildutils/Makefile.TLM.platform \
								SRC="$(SRC)" \
								CFLAGS="-DOVPSIM_GDB_DEBUG" \
								LDFLAGS="-L$(SCML_HOME)/lib-linux -lModelingObjects  -lscml_clock -lscml2 -lscml2_logging -lscml2_testing -lscml2_testing_systemc_main "

clean:
	$(MAKE) -f ${IMPERAS_HOME}/ImperasLib/buildutils/Makefile.TLM.platform \
								SRC="$(SRC)" \
								clean

#===============================================================================
# $FileName$
#===============================================================================
# vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
# vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:


