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
#include "Determinize.hh"
#include "tDeterminize.hh"

namespace Fsa {

ConstAutomatonRef localDeterminize(ConstAutomatonRef f) {
    return Ftl::localDeterminize<Automaton>(f);
}

ConstAutomatonRef determinize(ConstAutomatonRef f, bool disambiguate) {
    return Ftl::determinize<Automaton>(f, disambiguate);
}

ConstAutomatonRef removeDisambiguationSymbols(ConstAutomatonRef f) {
    return Ftl::removeDisambiguationSymbols<Automaton>(f);
}

ConstAutomatonRef removeInputDisambiguationSymbols(ConstAutomatonRef f) {
    return Ftl::removeInputDisambiguationSymbols<Automaton>(f);
}

ConstAutomatonRef replaceDisambiguationSymbols(ConstAutomatonRef f, LabelId ll) {
    return Ftl::replaceDisambiguationSymbols<Automaton>(f, ll);
}

ConstAutomatonRef replaceInputDisambiguationSymbols(ConstAutomatonRef f, LabelId ll) {
    return Ftl::replaceInputDisambiguationSymbols<Automaton>(f, ll);
}
}  // namespace Fsa
