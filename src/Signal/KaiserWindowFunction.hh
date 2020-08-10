/** Copyright 2020 RWTH Aachen University. All rights reserved.
 *
 *  Licensed under the RWTH ASR License (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.hltpr.rwth-aachen.de/rwth-asr/rwth-asr-license.html
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#ifndef _KAISER_WINDOW_FUNCTION_HH
#define _KAISER_WINDOW_FUNCTION_HH

#include "WindowFunction.hh"

namespace Signal {
/** KaiserWindowFunction */

class KaiserWindowFunction : public WindowFunction {
private:
    f64 beta_;

protected:
    virtual bool init();

public:
    KaiserWindowFunction(f64 beta = 0)
            : beta_(beta){};

    void setBeta(f64 beta) {
        beta_     = beta;
        needInit_ = true;
    }
};
}  // namespace Signal

#endif  // _KAISER_WINDOW_FUNCTION_HH
