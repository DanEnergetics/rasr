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
#include "Types.hh"

namespace Fsa {
Core::Choice TypeChoice(
        "unknown", TypeUnknown,
        "acceptor", TypeAcceptor,
        "transducer", TypeTransducer,
        Core::Choice::endMark());

Core::Choice PropertyChoice(
        "storage", PropertyStorage,
        "sorted-by-arc", PropertySortedByArc,
        "sorted-by-input", PropertySortedByInput,
        "sorted-by-output", PropertySortedByOutput,
        "linear", PropertyLinear,
        "acyclic", PropertyAcyclic,
        "cached", PropertyCached,
        Core::Choice::endMark());
}  // namespace Fsa
