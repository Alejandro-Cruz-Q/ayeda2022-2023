#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "sequence.h"
#include "dispersion_func.h"
#include "exploration_func.h"


template<class Key>
class HashTable{
  public:
    HashTable(const int tableSize, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe);
    bool search(const Key& k) const;
    bool insert(const Key& k);

  private: 
    const int tableSize_;
    std::vector<Sequence<Key>*> table_[];
    DispersionFunction<Key>* fd_;
    // blocksize
    ExplorationFunction<Key>* fe_;


};

#endif  // HASHTABLE_H