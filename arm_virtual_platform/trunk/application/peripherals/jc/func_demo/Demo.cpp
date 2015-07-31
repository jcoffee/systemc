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
 *      Fibonacci calulator
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
#include "Demo.h"

namespace jc {
namespace func_demo {

int Demo::fib(int i) {
    return (i > 1) ? fib(i - 1) + fib(i - 2) : i;
}

void Demo::demo() {

    printf("starting computing fibonacci\n");

    for (int i = 0; i < ITERATIONS; i++) {
        printf("fib(%d) = %d\n", i, fib(i));
    }
    printf("done computing fibonacci\n");

}

} /* namespace func_demo */
} /* namespace jc */

