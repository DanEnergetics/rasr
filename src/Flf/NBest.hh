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
#ifndef _FLF_N_BEST_HH
#define _FLF_N_BEST_HH

#include "FlfCore/Lattice.hh"
#include "Network.hh"

namespace Flf {

typedef enum {
    Eppstein,
    Mori
} NBestAlgorithm;
ConstLatticeRef nbest(ConstLatticeRef l, u32 n, bool removeDuplicates = true, NBestAlgorithm algo = Eppstein);

void dumpNBest(ConstLatticeRef l, std::ostream& os);

NodeRef createNBestNode(const std::string& name, const Core::Configuration& config);
NodeRef createSelectNBestNode(const std::string& name, const Core::Configuration& config);
NodeRef createDumpNBestNode(const std::string& name, const Core::Configuration& config);

}  // namespace Flf

#endif  // _FLF_N_BEST_HH
