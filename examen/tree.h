#ifndef TREE_H
#define TREE_H

#include <iostream>

template <class T>
class Node;
template <class T>
class Tree{
  private:
    Node<T>* root_;
  protected:
    virtual Node<T>& root();
  public:
    Tree() : root_() {};
    ~Tree();
    bool search(T&) = 0;
    bool insert(const T&) = 0;
    bool Delete(const T&) = 0;
    void inorden() = 0;
};
#endif