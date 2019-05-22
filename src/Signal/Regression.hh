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
// $Id$

#ifndef _SIGNAL_REGRESSION_HH
#define _SIGNAL_REGRESSION_HH

#include <Flow/Merger.hh>
#include <Flow/Vector.hh>

namespace Signal {

/**
 * Calculation of derivatives with linear regression coefficients.
 *
 * Here only the 1-dim. case for the second derivative is described.
 * All dimensions are handled independently.
 *
 * Given a symmetric window of e.g. +/- 2 frames, the regression
 * data can be defined as
 *
 *  x = [  -2,    -1,    0,    1,    2 ]^T
 *  f = [f(-2), f(-1), f(0), f(1), f(2)]^T   where f is a feature
 *
 * Assume now the vector y is generated by a polynomial
 *
 *  y  = b0 + b1*x + b2*x^2
 *  y" = 2*b2
 *
 * or, equivalently y = X*B with
 *
 *  X = [x.^0, x.^1, x.^2]    ->  5x3 input matrix
 *  B = [  b0,   b1,   b2]^T  ->  3x1 coefficients
 *
 * With least squares, we obtain
 *
 *  B = (X^T*X)^-1*X^T * f
 *    =              C * f
 *               (3x5) * (5x1) = (3x1) dim
 *
 * Thus the coefficient b2 is the last row of B and the second derivative
 * is approximated with the last row of C by
 *
 *  y" = 2 * b2
 *     ~ 2 * (C(end,:) * f)
 *
 * For the second derivative, the coefficients 2*C(end,:) result in
 *
 *  [2 -1 -2 -1 2]/7
 *
 * for the first derivative 1*C(end,:) = b1 (same idea, but start
 * with y = b0 + b1*x):
 *
 *  [-2 -1 0 -1 2]/10
 *
 * With some algebra, the derivatives can be calculated directly
 * by evaluating:
 *
 *  y' = (sum_i=1^2{ i*(  f(i) -  f(-i)) }) / (2*sum_i=1^2 i^2)
 *  y" = (sum_i=1^2{ i*( y'(i) - y'(-i)) }) / (2*sum_i=1^2 i^2)
 */

class Regression {
protected:
    typedef std::vector<f32> Frame;

public:
    Regression();
    ~Regression();
    void regressFirstOrder(const std::vector<const Frame*>& in, Frame& out);
    void regressSecondOrder(const std::vector<const Frame*>& in, Frame& out);
};

class RegressionNode : public Flow::MergerNode<Flow::Vector<f32>, Flow::Vector<f32>>,
                       private Regression {
    typedef Flow::MergerNode<Flow::Vector<f32>, Flow::Vector<f32>> Precursor;

private:
    u32 order_;

public:
    static std::string filterName() {
        return "signal-regression";
    }
    static const Core::ParameterInt parameterOrder;

    RegressionNode(const Core::Configuration& c);
    virtual ~RegressionNode();

    virtual bool                   setParameter(const std::string& name, const std::string& value);
    virtual Precursor::OutputData* merge(std::vector<Precursor::InputFrame>&);
};

}  // namespace Signal

#endif  // _SIGNAL_REGRESSION_HH
