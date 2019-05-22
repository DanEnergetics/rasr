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
#ifndef _SIGNAL_MODULES_HH
#define _SIGNAL_MODULES_HH

/*
 * signal network application:
 */

#include <Core/Singleton.hh>

namespace Signal {

class Module_ {
public:
    Module_();
};

typedef Core::SingletonHolder<Module_> Module;
}  // namespace Signal

#endif  // _SIGNAL_MODULES_HH
