#ifndef DISPERSIONFUNC_H
#define DISPERSIONFUNC_H

template<class Key>
class DispersionFunction {
  public:
    unsigned operator()(const Key& k) const = 0;
};

#endif  // DISPERSIONFUNC_H