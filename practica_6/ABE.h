#ifndef ABE_H_
#define ABE_H_

#include "AB.h"
#include "NodoB.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <deque>
#include <queue>
#include <utility>

template<class Key>
class ABE : public AB<Key> {
  public:
    ABE(): raiz_(nullptr) {};
    int tamRama(NodoB<Key>* rama);
    bool insert(const Key& k);
    void insertNode(const Key& k, NodoB<Key>* rama);
    bool search(const Key& k);
    bool searchNode(const Key& k, NodoB<Key>* rama);
    void inOrden(NodoB<Key>* nodo);
    NodoB<Key>* getRaiz() { return raiz_; };
  private:
    NodoB<Key>* raiz_;
};

template<class Key>
int ABE<Key>::tamRama(NodoB<Key>* rama) {
  if (rama == nullptr) {
    return 0;
  } else {
    return 1 + tamRama(rama->getIzq()) + tamRama(rama->getDer());
  }
}

template<class Key>
bool ABE<Key>::insert(const Key& k) {
  if (search(k)) return false;
  if (raiz_ == nullptr) {
    raiz_ = new NodoB<Key>(k);
  } else {
    insertNode(k, raiz_);
  }
  return true;
}

template<class Key>
void ABE<Key>::insertNode(const Key& k, NodoB<Key>* rama) {
  if (tamRama(rama->getIzq()) <= tamRama(rama->getDer())) {
    if (rama->getIzq() != nullptr) {
      insertNode(k, rama->getIzq());
    } else {
      rama->setIzq(k);
    }
  } else {
    if (rama->getDer() != nullptr) {
      insertNode(k, rama->getDer());
    } else {
      rama->setDer(k);
    }
  }
}

template<class Key>
bool ABE<Key>::search(const Key& k) {
  return searchNode(k, raiz_);
}

template<class Key>
bool ABE<Key>::searchNode(const Key& k, NodoB<Key>* raiz) {
  std::deque<std::pair<NodoB<Key>*, int>> Q;
  NodoB<Key>* aux;
  int nivel = 0; 
  Q.push_back(std::pair<NodoB<Key>*, int>(raiz, 0));
  while (!Q.empty()) {
    aux = Q.front().first;
    nivel = Q.front().second;
    Q.pop_front();
    if (aux != nullptr) {
      if (aux->getData() == k) return true;
      Q.push_back(std::pair<NodoB<Key>*, int>(aux->getIzq(), nivel + 1));
      Q.push_back(std::pair<NodoB<Key>*, int>(aux->getDer(), nivel + 1));
    }
  }
  return false;
}

template<class Key>
void ABE<Key>::inOrden(NodoB<Key>* nodo) {
  if (nodo != nullptr) {
    inOrden(nodo->getIzq());
    std::cout << nodo->getData() << " ";
    inOrden(nodo->getDer());
  }
}

template<class Key>
std::ostream& operator<<(std::ostream& os, AB<Key>* ab) {
  NodoB<Key>* raiz = ab->getRaiz();
  std::deque<std::pair<NodoB<Key>*, int>> Q;
  NodoB<Key>* aux;
  int nivel = 0; 
  int nivel_actual = 0;
  Q.push_back(std::pair<NodoB<Key>*, int>(raiz, 0));
  os << "\n Nivel 0:";
  while (!Q.empty()) {
    aux = Q.front().first;
    nivel = Q.front().second;
    Q.pop_front();
    if (nivel > nivel_actual) {
      nivel_actual = nivel;
      os << "\n Nivel " << nivel_actual << ":";
    }
    if (aux != nullptr) {
      os << "[" << aux->getData() << "] ";
      Q.push_back(std::pair<NodoB<Key>*, int>(aux->getIzq(), nivel + 1));
      Q.push_back(std::pair<NodoB<Key>*, int>(aux->getDer(), nivel + 1));
    } else {
      os << "[.] ";
    }
  }
  return os;
}

#endif // ABE_H_