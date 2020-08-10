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
#ifndef _T_FSA_MINIMIZE_HH
#define _T_FSA_MINIMIZE_HH

#include "Types.hh"

namespace Ftl {

template<class _Automaton>
typename _Automaton::ConstRef minimize(typename _Automaton::ConstRef f, bool progress = false);

template<class _Automaton>
typename _Automaton::ConstRef minimize(typename _Automaton::ConstRef f, Fsa::OptimizationHint hint, bool progress = false);

template<class _Automaton>
typename _Automaton::ConstRef minimizeSimple(typename _Automaton::ConstRef f);

}  // namespace Ftl

#include "tMinimize.cc"

#endif  // _T_FSA_MINIMIZE_HH
