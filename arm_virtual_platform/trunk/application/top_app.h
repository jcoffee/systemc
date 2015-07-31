/**@file
 * @copyright
 *      This file is subject to the terms and conditions defined in
 *      file 'LICENSE.txt', which is part of this source code package.
 * @author
 *      Pham Hung Cuong (cuongph.et@gmail.com)
 * @date
 *      June 04, 2015
 *
 * @brief
 *      Top application
 *
 -------------------------------------------------------------------------------
 Revision information:
 - $ProjectName::                                                              $
 - $ReleaseDate::                                                              $
 - $ReleaseVersion::                                                           $
 - $Revision:: 811                                                             $
 - $LastChangedBy:: cuongph8                                                   $
 - $LastChangedDate:: 2015-08-01 00:12:30 +0700 (Sat, 01 Aug 2015)             $
 - $FilePath::                                                                 $
 -------------------------------------------------------------------------------
*/

#ifndef JC_TOP_APP_H_
#define JC_TOP_APP_H_

// makefile include path: ${ARM_TOOLCHAIN_ROOT}/arm-none-eabi/include
#include <stdlib.h>
#include <stdio.h>
#define LOG(_FMT, ...) printf( "TEST: " _FMT,  ## __VA_ARGS__)

#include "peripherals/jc_reuse/uart_16450/Uart.h"
typedef ::jc_reuse::uart_16450::uart ovp_uart;

#include "peripherals/jc_reuse/timer_arm_sp804/Timer.h"
typedef ::jc_reuse::timer_arm_sp804::Timer ovp_timer;

#include "peripherals/jc/func_demo/Demo.h"
typedef ::jc::func_demo::Demo jc_demo;

class Top_app {
private:
public:
    static int run_app();

};

#endif // JC_TOP_APP_H_
//===============================================================================
// $FileName$
//===============================================================================
// vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
// vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
