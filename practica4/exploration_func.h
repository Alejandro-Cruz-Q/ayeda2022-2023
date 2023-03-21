#ifndef EXPLORATIONFUNC_H
#define EXPLORATIONFUNC_H

template<class Key>
class ExplorationFunction {
  public:
    unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif  // EXPLORATIONFUNC_H