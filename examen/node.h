#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node{
  protected:
    int nData_;
    int nLink_;
  public:
    T& get(int i) const = 0;
    Node<T>& link(int i) const = 0;
};

#endif