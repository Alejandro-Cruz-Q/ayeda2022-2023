#ifndef MWAYTREE_H
#define MWAYTREE_H

#include "gtree.h"

template <class T, int G>
class MWayTree : public GTree<T,G>{
  private:
    GNode<T,G> root_;
  public:
    MWayTree() : root_() {};
    ~MWayTree();
    bool search(T&);
    bool insert(const T&);
    bool Delete(const T&);
    void inorden();
};

// template <class T, int G>
// bool insert(const T& dato){
//   GNode<T,G> raiz = root();
//   for(int i = 0; i < raiz.-1; i++){
//     if(raiz.get(i) > dato )
//   }
// }

#endif 