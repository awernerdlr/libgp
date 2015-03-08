// libgp - Gaussian process library for Machine Learning
// Copyright (c) 2013, Manuel Blum <mblum@informatik.uni-freiburg.de>
// All rights reserved.

#include "sampleset.h"
#include <Eigen/StdVector>

namespace libgp {
  
  SampleSet::SampleSet (int input_dim)
  {
    this->input_dim = input_dim;
  }
  
  SampleSet::~SampleSet() {}
  
  void SampleSet::add(const double x[], double y)
  {
    Eigen::Map<const Eigen::VectorXd> map(x,input_dim);
    inputs.push_back(map);
    targets.push_back(y);
    assert(inputs.size()==targets.size());
  }
  
  void SampleSet::add(const Eigen::VectorXd & x, double y)
  {
    inputs.push_back(x);
    targets.push_back(y);
    assert(inputs.size()==targets.size());
  }
  
  const Eigen::VectorXd & SampleSet::x(size_t k)
  {
    return inputs.at(k);
  }

  double SampleSet::y(size_t k)
  {
    return targets.at(k);
  }

  const std::vector<double>& SampleSet::y() 
  {
    return targets;
  }

  bool SampleSet::set_y(size_t i, double y)
  {
    if (i>=inputs.size()) return false;
    targets[i] = y;
    return true;
  }
  
  size_t SampleSet::size()
  {
    return inputs.size();
  }
  
  void SampleSet::clear()
  {
    inputs.clear();
    targets.clear();
  }
  
  bool SampleSet::empty ()
  {
    return inputs.size()==0;
  }
}
