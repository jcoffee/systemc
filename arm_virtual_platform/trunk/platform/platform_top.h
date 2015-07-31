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
 *      Top platform
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
#ifndef JC_ARM_VIRTUAL_PLATFORM_PLATFORM_TOP_H_
#define JC_ARM_VIRTUAL_PLATFORM_PLATFORM_TOP_H_

#include <systemc>
using namespace sc_core;

#include <tlm.h>
/// Platform debugger, inspector
#include <ovpworld.org/modelSupport/tlmPlatform/1.0/tlm2.0/tlmPlatform.hpp>
/// OVP CPU
#include <arm.ovpworld.org/processor/arm/1.0/tlm2.0/processor.igen.hpp>
/// OVP bus interconnect
#include <ovpworld.org/modelSupport/tlmDecoder/1.0/tlm2.0/tlmDecoder.hpp>
/// OVP memories
#include <ovpworld.org/memory/ram/1.0/tlm2.0/tlmMemory.hpp>
/// OVP UART peripheral
#include <national.ovpworld.org/peripheral/16450/1.0/tlm2.0/pse.igen.hpp>
typedef  _16450 Uart16450;
/// OVP Timer peripheral
#include <arm.ovpworld.org/peripheral/TimerSP804/1.0/tlm2.0/pse.igen.hpp>


namespace jc {
namespace arm_virtual_platform {

class platform_top : public sc_module {
public:
    platform_top (sc_core::sc_module_name name
                 ,const char*             variant
                 );

    icmTLMPlatform      platform;       ///< Platform debugger, inspector
    arm                 cpu1;           ///< OVP CPU
    decoder<2,6>        bus1;           ///< OVP bus interconnect
    ram                 sysmem;         ///< OVP memories
    ram                 rom;            ///< OVP memories
    ram                 sram;           ///< OVP memories
    ram                 sdram;          ///< OVP memories
    Uart16450           uart1;          ///< OVP UART peripheral
    TimerSP804          timer1;         ///< OVP Timer peripheral

private:
    icmAttrListObject* ovpcpu1_getAttrs(const char* variant);
    icmAttrListObject* ovpuart1_getAttrs();
    icmAttrListObject* ovptimer1_getAttrs();

    void start_of_simulation();
    void end_of_simulation();

}; /* platform_top */

} // namespace jc
} // namespace arm_virtual_platform

#endif // JC_ARM_VIRTUAL_PLATFORM_PLATFORM_TOP_H_
//===============================================================================
// $FileName$
//===============================================================================
// vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
// vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
