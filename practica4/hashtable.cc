#include "hashtable.h"

template <class Key>
HashTable<Key>::HashTable(const int tableSize, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe){
  std::vector<Sequence<Key>*> table[tableSize];
  tableSize_ = tableSize;
  table_ = table;
  fd_ = fd;
  fe_ = fe;
}