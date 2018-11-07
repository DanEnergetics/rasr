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
#ifndef _TENSORFLOW_FORWARD_NODE_HH
#define _TENSORFLOW_FORWARD_NODE_HH

#include <deque>

#include <Flow/Attributes.hh>
#include <Flow/Datatype.hh>
#include <Flow/Node.hh>
#include <Flow/Timestamp.hh>
#include <Mm/Types.hh>

#include "GraphLoader.hh"
#include "Session.hh"
#include "Tensor.hh"
#include "TensorMap.hh"

namespace Tensorflow {

class TensorflowForwardNode : public Flow::Node {
public:
    typedef Flow::Node Precursor;

    static Core::ParameterString paramId;
    static Core::ParameterInt    paramBufferSize;
    static Core::ParameterBool   paramCheckValues;

    static std::string filterName();

    TensorflowForwardNode(Core::Configuration const& c);
    virtual ~TensorflowForwardNode() = default;

    virtual Flow::PortId getInput(std::string const& name);
    virtual Flow::PortId getOutput(std::string const& name);
    //virtual bool configure();
    virtual bool setParameter(const std::string& name, const std::string& value);
    virtual bool work(Flow::PortId p);

private:
    const size_t bufferSize_;   // number of features that are processed at once
    const bool   checkValues_;  // check output of network for finiteness
    bool         eos_;          // needs initialization of network

    // port management
    std::vector<std::string>                      input_port_names_;
    std::vector<std::string>                      output_port_names_;
    std::unordered_map<std::string, Flow::PortId> input_port_map_;
    std::unordered_map<std::string, Flow::PortId> output_port_map_;
    std::vector<std::string>                      output_tensor_names_;

    // tensorflow related members
    Session                            session_;
    std::unique_ptr<GraphLoader>       loader_;
    std::unique_ptr<Tensorflow::Graph> graph_;
    TensorInputMap                     tensor_input_map_;
    TensorOutputMap                    tensor_output_map_;

    std::vector<Flow::Timestamp>          timestamps_;
    std::vector<std::vector<Flow::Data*>> outputs_;
    std::vector<size_t>                   current_output_frame_;

    Tensorflow::Tensor toTensor(std::vector<Flow::DataPtr<Flow::Timestamp>> const& data) const;
    template<typename T>
    Tensorflow::Tensor vectorToTensor(std::vector<Flow::DataPtr<Flow::Timestamp>> const& data) const;

    void appendToOutput(Tensor const& tensor, size_t start_frame, std::vector<Flow::Data*>& data) const;
    template<typename T>
    void appendVectorsToOutput(Tensor const& tensor, size_t start_frame, std::vector<Flow::Data*>& data) const;
};

// inline implementations
inline std::string TensorflowForwardNode::filterName() {
    return std::string("tensorflow-forward");
};

}  // namespace Tensorflow

#endif  // _TENSORFLOW_FORWARD_NODE_HH
