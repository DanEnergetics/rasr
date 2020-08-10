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
#ifndef _LM_CHEATING_SEGMENT_LM_HH
#define _LM_CHEATING_SEGMENT_LM_HH

#include <Bliss/Orthography.hh>

#include "FsaLm.hh"

namespace Lm {

class CheatingSegmentLm : public FsaLm {
public:
    using Precursor = FsaLm;

    static const Core::ParameterFloat paramInfinityScore;

    CheatingSegmentLm(Core::Configuration const& c, Core::Ref<const Bliss::Lexicon> l);
    virtual ~CheatingSegmentLm() = default;

    virtual void load();
    virtual void setSegment(Bliss::SpeechSegment const* s);

private:
    Core::Ref<const Bliss::Lexicon>            lexicon_;
    Core::Ref<const Bliss::OrthographicParser> orthParser_;
};

// inline implementation

inline CheatingSegmentLm::CheatingSegmentLm(Core::Configuration const& c, Bliss::LexiconRef l)
        : Core::Component(c), Precursor(c, l), lexicon_(l), orthParser_(Core::ref(new Bliss::OrthographicParser(config, lexicon_))) {
    infinityScore_ = paramInfinityScore(config);
}

}  // namespace Lm

#endif  // _LM_CHEATING_SEGMENT_LM_HH
