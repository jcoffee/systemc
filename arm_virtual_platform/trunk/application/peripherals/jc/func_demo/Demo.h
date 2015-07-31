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
#ifndef PERIPHERALS_JC_FUNC_DEMO_H_
#define PERIPHERALS_JC_FUNC_DEMO_H_

#include <stdio.h>
#include <stdint.h>

namespace jc {
namespace func_demo {

class Demo {
public:
    enum DEMO_CNST {
        ITERATIONS = 20
    };

    Demo();
    ~Demo();

    static int fib(int i);
    static void demo();

};

} /* namespace func_demo */
} /* namespace jc */

#endif /* PERIPHERALS_JC_FUNC_DEMO_H_ */
