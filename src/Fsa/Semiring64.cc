/** Copyright 2018 RWTH Aachen University. All rights reserved.
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
#include "tRealSemiring.hh"
#include "Semiring64.hh"

namespace Fsa {
        typedef Ftl::LogSemiring<Weight64, f64> LogSemiring64_;

    class PredefinedLogSemiring64_ : public LogSemiring64_ {
    public:
        PredefinedLogSemiring64_() : LogSemiring64_(1) {}
        std::string name() const { return "log64"; }
    };
    ConstSemiring64Ref LogSemiring64 = ConstSemiring64Ref(new PredefinedLogSemiring64_());
} // namespace Fsa
