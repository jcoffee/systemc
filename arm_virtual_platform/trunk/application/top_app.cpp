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

#include "top_app.h"

int Top_app::run_app() {
    jc_demo::demo();

    return EXIT_SUCCESS;
}

//===============================================================================
// $FileName$
//===============================================================================
// vim:ft=make:nowrap:tw=0:sw=4:ts=4:sts=4:smarttab:noexpandtab:hlsearch:incsearch:ignorecase:
// vim:smartcase:fo=tcq2:fdm=indent:foldenable:autoindent:smartindent:norl:autoread:nobackup:
