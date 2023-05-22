#ifndef GNODE_H
#define GNODE_H

#include <iostream>

#include "node.h"


template <class T, int G>
class GNode : public Node<T>{
  private:
    T Data[G-1];
    GNode<T,G>* Link[G];
  protected:
    int nData_;
    int nLink_;
  public:
    T& get(int i) const{return Data[i];};
    GNode<T,G>& link(int i) const {return Link[i];};
};

#endif