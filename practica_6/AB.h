#ifndef AB_H_
#define AB_H_

#include "NodoB.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <deque>
#include <queue>
#include <utility>

template <class Key>
class AB {
  public:
    virtual bool insert(const Key& k) = 0;
    virtual bool search(const Key& k) = 0;
    virtual void inOrden(NodoB<Key>* nodo) = 0;
    virtual NodoB<Key>* getRaiz() = 0;
};

#endif // AB_H_