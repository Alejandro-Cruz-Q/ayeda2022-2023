#ifndef GTREE_H
#define GTREE_H

#include <iostream>

#include "tree.h"

template <class T, int G>
class GNode;
template <class T, int G>
class GTree : public Tree<T>{
  private:
    GNode<T,G> root_;
  protected:
    GNode<T,G>& root();
  public:
    GTree() : root_() {};
    ~GTree();
    bool search(T&) = 0;
    bool insert(const T&) = 0;
    bool Delete(const T&) = 0;
    void inorden();
};

template <class T, int G>
void inorden(){
  GNode<T,G> raiz = root();
  raiz.link(0);
}

#endif