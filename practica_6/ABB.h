#ifndef ABB_H_
#define ABB_H_

#include "NodoB.h"
#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
  public:
    ABB() : raiz_(nullptr) {};
    ~ABB();
    bool insert(const Key& k);
    bool search(const Key& k) ;
    bool remove(const Key& k);
    void inOrden(NodoB<Key>* nodo);
    NodoB<Key>* getRaiz() { return raiz_; };
  private:
    NodoB<Key>* raiz_;

    void podar(NodoB<Key>* nodo);
    int size();
    int size_rama(NodoB<Key>* nodo);
    int altura();
    int altura_nodo(NodoB<Key>* nodo);
    void insertNode(const Key& k, NodoB<Key>* nodo);
    bool searchNode(const Key& k, NodoB<Key>* nodo);
    void removeNode(const Key& k, NodoB<Key>* nodo);
    void sustituir(NodoB<Key>* eliminado, NodoB<Key>* sustituto);
};

template<class Key>
ABB<Key>::~ABB() {
  podar(raiz_);
}

template<class Key>
void ABB<Key>::podar(NodoB<Key>* nodo) {
  if (nodo == nullptr) return;
  podar(nodo->getIzq());
  podar(nodo->getDer());
  delete nodo;
  nodo = nullptr;
}

template<class Key>
int ABB<Key>::size() {
  return size_rama(raiz_);
}

template<class Key>
int ABB<Key>::size_rama(NodoB<Key>* nodo) {
  if (nodo == nullptr) return 0;
  return 1 + size_rama(nodo->getIzq()) + size_rama(nodo->getDer());
}

template<class Key>
int ABB<Key>::altura() {
  return altura_nodo(raiz_);
}

template<class Key>
int ABB<Key>::altura_nodo(NodoB<Key>* nodo) {
  if (nodo == nullptr) return 0;
  return 1 + std::max(altura_nodo(nodo->getIzq()), altura_nodo(nodo->getDer()));
}

template<class Key>
bool ABB<Key>::search(const Key& k) {
  return searchNode(k, raiz_);
}

template<class Key>
bool ABB<Key>::searchNode(const Key& k, NodoB<Key>* nodo) {
  if (nodo == nullptr) return false;
  if (k == nodo->getData()) return true;
  if (k < nodo->getData()) {
    return searchNode(k, nodo->getIzq());
  } else {
    return searchNode(k, nodo->getDer());
  }
}

template<class Key>
bool ABB<Key>::insert(const Key& k) {
  if (search(k)) return false;
  if (raiz_ == nullptr) raiz_ = new NodoB<Key>(k);
  else {
    insertNode(k, raiz_); 
  }
  return true;
}

template<class Key>
void ABB<Key>::insertNode(const Key& k, NodoB<Key>* nodo) {
  if (k < nodo->getData()) {
    if (nodo->getIzq() == nullptr) {
      nodo->setIzq(k);
    } else {
      insertNode(k, nodo->getIzq());
    }
  }
  if (k > nodo->getData()) {
    if (nodo->getDer() == nullptr) {
      nodo->setDer(k);
    } else {
      insertNode(k, nodo->getDer());
    }
  }
}

template<class Key>
bool ABB<Key>::remove(const Key& k) {
  if (!search(k)) return false;
  else {
    removeNode(k, raiz_);
    return true;
  }
}

template<class Key>
void ABB<Key>::removeNode(const Key& k, NodoB<Key>* nodo) {
  if (nodo == nullptr) return;
  if (k < nodo->getData()) {
    removeNode(k, nodo->getIzq());
  } else if (k > nodo->getData()) {
    removeNode(k, nodo->getDer());
  } else {
    NodoB<Key>* eliminado = nodo;
    if (nodo->getDer() == nullptr)
      nodo = nodo->getIzq();
    else if (nodo->getIzq() == nullptr)
      nodo = nodo->getDer();
    else 
      sustituir(eliminado, nodo->getIzq());
    delete eliminado;
  }
}

template<class Key>
void ABB<Key>::sustituir(NodoB<Key>* eliminado, NodoB<Key>* sustituto) {
  if (sustituto->getDer() == nullptr)
    sustituir(eliminado, sustituto->getDer());
  else {
    eliminado->setData(sustituto->getData());
    eliminado = sustituto;
    sustituto = sustituto->getIzq();
  }
}

template<class Key>
void ABB<Key>::inOrden(NodoB<Key>* nodo) {
  if (nodo != nullptr) {
    inOrden(nodo->getIzq());
    std::cout << nodo->getData() << " ";
    inOrden(nodo->getDer());
  }
}

#endif // ABB_H_