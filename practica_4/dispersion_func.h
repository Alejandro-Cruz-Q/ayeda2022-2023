#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H

#include <cstdlib>

template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator() (Key const &k) const = 0;
};

template<class Key>
class FDModule : public DispersionFunction<Key> {
 public:
  FDModule(unsigned const n) : table_size_(n) { }
  unsigned operator() (Key const &k) const {
    return k % table_size_;
  }
 private:
  unsigned table_size_;
};

template<class Key>
class FDBasedOnSum : public DispersionFunction<Key> {
 public:
  FDBasedOnSum(unsigned const n) : table_size_(n) { }
  unsigned operator() (Key const &k) const {
    Key k_copy = k;
    Key sum_final_value{0};
    while (k_copy > 0) {
      Key aux_var = k_copy % 10;
      sum_final_value = sum_final_value + aux_var;
      k_copy = k_copy / 10;
    }
    return sum_final_value % table_size_;
  }
 private:
  unsigned table_size_;
};

template<class Key>
class FDPseudorandom : public DispersionFunction<Key> {
 public:
  FDPseudorandom(unsigned const n) : table_size_(n) { }
  unsigned operator() (Key const &k) const {
    srand(k);
    return rand() % table_size_;
  }
 private:
  unsigned table_size_;
};

#endif