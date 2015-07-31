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
#include "platform_top.h"

namespace jc {
namespace arm_virtual_platform {


platform_top::platform_top (sc_core::sc_module_name name
                           ,const char*             variant
)   : sc_core::sc_module (name)
    //--------------------------------------------------------------------------
    // Initialize the OVP platform
    //--------------------------------------------------------------------------
    , platform ("icm"                            // sc_module_name module_name,                      @param module_name     A unique name for the platform.
               ,ICM_VERBOSE | ICM_STOP_ON_CTRLC  // icmInitAttrs   simAttrs    = ICM_INIT_DEFAULT,   @param simAttrs        (optional) global simulation attributes.
#ifdef OVPSIM_GDB_DEBUG
               ,"db"                             // const char    *dbgProtocol = NULL,               @param dbgProtocol     (optional) Protocol used by debugger.
               ,10000                            // Uns32          dbgPort     = 0                   @param dbgPort         (optional) Debugger port number.
#endif // OVPSIM_GDB_DEBUG
               )
    //--------------------------------------------------------------------------
    // Initialize OVP CPU and OVP bus master
    //--------------------------------------------------------------------------
    , cpu1 ("cpu1"                    // sc_module_name        name,
           ,0                         // const unsigned int    ID,
           ,ICM_ATTR_DEFAULT          // icmNewProcAttrs       attrs        = ICM_ATTR_DEFAULT,
           ,ovpcpu1_getAttrs(variant) // icmAttrListObject    *attrList    = NULL,
           ,NULL                      // const char           *semiHost    = NULL,
           ,32                        // Uns32                 addressBits = 32,
           ,false                     // bool                  dmi         = true,
           ,0                         // Uns32                 cpuFlags    = 0
           )
    // OVP bus
    , bus1("bus1")
    //--------------------------------------------------------------------------
    // Initialize OVP Memories
    //--------------------------------------------------------------------------
    , sysmem("system_mem" // sc_core::sc_module_name   module_name              ///< SC module name
            ,"sp1"        // const char               *memory_socket            ///< socket name
            ,0x00100000   // sc_dt::uint64             high_address             ///< memory size (bytes-1)
            ,4            // unsigned int              memory_width = 4         ///< memory width (bytes)
            )
    , rom   ("rom"        // sc_core::sc_module_name   module_name              ///< SC module name
            ,"sp1"        // const char               *memory_socket            ///< socket name
            ,0x00014000   // sc_dt::uint64             high_address             ///< memory size (bytes-1)
            ,4            // unsigned int              memory_width = 4         ///< memory width (bytes)
            )
    , sram  ("sram"       // sc_core::sc_module_name   module_name              ///< SC module name
            ,"sp1"        // const char               *memory_socket            ///< socket name
            ,0x00010000   // sc_dt::uint64             high_address             ///< memory size (bytes-1)
            ,4            // unsigned int              memory_width = 4         ///< memory width (bytes)
            )
    , sdram ("sdram"      // sc_core::sc_module_name   module_name              ///< SC module name
            ,"sp1"        // const char               *memory_socket            ///< socket name
            ,0x20000000   // sc_dt::uint64             high_address             ///< memory size (bytes-1)
            ,4            // unsigned int              memory_width = 4         ///< memory width (bytes)
        )
    //--------------------------------------------------------------------------
    // Initialize OVP Peripherals
    //--------------------------------------------------------------------------
    , uart1 ("uart1"
            ,ovpuart1_getAttrs()
            )
    , timer1("timer1"
            ,ovptimer1_getAttrs()
            )
{
    uint8_t add_map_cnt = 0;
    //--------------------------------------------------------------------------
    // Connect OVP CPU and OVP bus1 master
    //--------------------------------------------------------------------------
    cpu1.INSTRUCTION.socket (bus1.target_socket[0]);
    cpu1.DATA.socket        (bus1.target_socket[1]);

    //--------------------------------------------------------------------------
    // Demo OVP Memories
    //--------------------------------------------------------------------------
    bus1.initiator_socket[add_map_cnt](sysmem.sp1);
    bus1.setDecode(add_map_cnt
                  ,0x00000000
                  ,0x000fffff
                  );
    add_map_cnt++;

    bus1.initiator_socket[add_map_cnt](rom.sp1);
    bus1.setDecode(add_map_cnt
                  ,0x40000000
                  ,0x40013fff
                  );
    add_map_cnt++;

    bus1.initiator_socket[add_map_cnt](sram.sp1);
    bus1.setDecode(add_map_cnt
                  ,0x40200000
                  ,0x4020ffff
                  );
    add_map_cnt++;

    bus1.initiator_socket[add_map_cnt](sdram.sp1);
    bus1.setDecode(add_map_cnt
                  ,0x80000000
                  ,0x9fffffff
                  );
    add_map_cnt++;

    //--------------------------------------------------------------------------
    // Demo OVP Peripherals
    //--------------------------------------------------------------------------
    bus1.initiator_socket[add_map_cnt](uart1.bport1.socket);
    bus1.setDecode(add_map_cnt
                  ,0x49000000
                  ,0x49000007
                  );
    add_map_cnt++;

    bus1.initiator_socket[add_map_cnt](timer1.bport1.socket);
    bus1.setDecode(add_map_cnt
                  ,0x49300000
                  ,0x493000ff
                  );
    add_map_cnt++;

    //--------------------------------------------------------------------------
    // Net connections
    //--------------------------------------------------------------------------


}


icmAttrListObject* platform_top::ovpcpu1_getAttrs(const char* variant) {
    icmAttrListObject* userAttrs = new icmAttrListObject;
    userAttrs->addAttr("endian",        "little");
    userAttrs->addAttr("compatibility", "nopSVC");
    userAttrs->addAttr("variant",       variant);
    userAttrs->addAttr("UAL",           "1");
    return userAttrs;
}

icmAttrListObject* platform_top::ovpuart1_getAttrs() {
    icmAttrListObject* userAttrs = new icmAttrListObject;
    userAttrs->addAttr("outfile", "uart1.log");
    userAttrs->addAttr("log",     "1");
    return userAttrs;
}

icmAttrListObject* platform_top::ovptimer1_getAttrs() {
    return NULL;
}

void platform_top::start_of_simulation() {}
void platform_top::end_of_simulation() {}

} // namespace jc
} // namespace arm_virtual_platform

//===============================================================================
// $FileName$
//===============================================================================
// vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
// vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
