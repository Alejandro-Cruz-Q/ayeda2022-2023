#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include <iostream>
#include <vector>

template<class Key>
class SortMethod {
  protected: 
    unsigned size;
    std::vector<Key> seq;
  public:
    void Sort( ) = 0;
};

#endif // SORTMETHOD_H