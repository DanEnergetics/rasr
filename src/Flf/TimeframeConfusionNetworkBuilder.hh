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
#ifndef _FLF_TIMEFRAME_CONFUSION_NETWORK_BUILDER_HH
#define _FLF_TIMEFRAME_CONFUSION_NETWORK_BUILDER_HH

#include "FlfCore/Lattice.hh"
#include "FwdBwd.hh"
#include "Network.hh"


namespace Flf {

    /**
     * Build framewise posterior CN from fwd/bwd scores
     **/
    ConstPosteriorCnRef buildFramePosteriorCn(ConstLatticeRef l, ConstFwdBwdRef fwdBwd);
    /**
     * Build framewise posterior CN from scores stored in dimension "id"
     **/
    ConstPosteriorCnRef buildFramePosteriorCn(ConstLatticeRef l, ScoreId id);

    NodeRef createFramePosteriorCnBuilderNode(const std::string &name, const Core::Configuration &config);

} // namespace Flf

#endif // _FLF_TIMEFRAME_CONFUSION_NETWORK_BUILDER_HH
