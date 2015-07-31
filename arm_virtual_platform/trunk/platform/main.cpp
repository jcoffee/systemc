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
 *      Main file
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
#include <systemc>
using namespace sc_core;

#include "platform_top.h"
typedef ::jc::arm_virtual_platform::platform_top  arm_platform;

int sc_main(int argc, char* argv[]) {
    const char* pVariant;
    const char* pExe;

    if (argc >= 2) {
        pExe     = argv[1];
        pVariant = argv[2];
        cout << "variant:" << pVariant << endl;
        cout << "exe:"     << pExe << endl;
    } else {
        cout << "Usage: platform.exe <application>" << endl;
        cout << "       Please specify application" << endl;
        return EXIT_FAILURE;
    }

    // Ignore some of the Warning messages
    icmIgnoreMessage ("ICM_NPF");
    // Ignore specific message that compatibility mode causes
    icmIgnoreMessage("ARM_MORPH_BII");

    cout << "Constructing." << endl;
    arm_platform top("arm_platform", pVariant);

#ifdef OVPSIM_GDB_DEBUG
    top.cpu1.debugThisProcessor();
#endif
    cout << "Load executable file\n" << endl;
    top.cpu1.loadLocalMemory(pExe
                            ,(icmLoaderAttrs)(ICM_LOAD_VERBOSE
                                             |ICM_SET_START
                                             )
                            );


    sc_core::sc_start();


    return EXIT_SUCCESS;
}

//===============================================================================
// $FileName$
//===============================================================================
// vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
// vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
