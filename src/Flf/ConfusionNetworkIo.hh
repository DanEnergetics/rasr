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
#ifndef _FLF_CONFUSION_NETWORK_IO_HH
#define _FLF_CONFUSION_NETWORK_IO_HH

#include <Core/BinaryStream.hh>
#include <Core/XmlStream.hh>

#include "FlfCore/Lattice.hh"
#include "Io.hh"
#include "Network.hh"

namespace Flf {

    /**
     * Input
     **/
    ConstConfusionNetworkRef readConfusionNetworkFromXml(std::istream &is, ConfusionNetworkRef cn = ConfusionNetworkRef());

    /**
     * Ouput
     **/
    void writeConfusionNetworkAsText(std::ostream &os, ConstConfusionNetworkRef cn, ConstSegmentRef segment);
    void writeConfusionNetworkAsXml(Core::XmlWriter &xml, ConstConfusionNetworkRef cn, ConstSegmentRef segment, u32 ioFlag = IoFlag::WriteAll);

    NodeRef createDumpConfusionNetworkNode(const std::string &name, const Core::Configuration &config);

} // namespace Flf

#endif // _FLF_CONFUSION_NETWORK_IO_HH
