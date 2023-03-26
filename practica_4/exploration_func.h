#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H

#include "dispersion_func.h"

template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator() (Key const &k, unsigned i) const = 0;
};

template<class Key>
class EFLineal : public ExplorationFunction<Key> {
 public:
  unsigned operator() (Key const &k, unsigned i) const {
    return i;
  }
};

template<class Key>
class EFQuadratic : public ExplorationFunction<Key>{
  unsigned operator() (Key const &k, unsigned i) const {
    return i*i;
  }
};

template<class Key>
class EFDoubleScatter : public ExplorationFunction<Key> {
 public: 
  EFDoubleScatter(DispersionFunction<Key> *dispersion_function) : dispersion_function_(dispersion_function) {}
  unsigned operator() (Key const &k, unsigned i) const {
    return dispersion_function_->operator()(k) * i;
  }
 private:
  DispersionFunction<Key> *dispersion_function_;
};

template<class Key>
class EFRedispersion : public ExplorationFunction<Key> {
 public:
  unsigned operator() (Key const &k, unsigned i) const {
    srand(k);
    unsigned displacement{0};
    for (int j{0}; j < i; ++j) {
      displacement = rand();
    }
    return displacement;
  }
};
#endif