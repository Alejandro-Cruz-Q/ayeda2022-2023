#ifndef NODOB_H_
#define NODOB_H_

template<class Key>
class NodoB {
  public:
    NodoB(const Key& k, NodoB* izq = nullptr, NodoB* der = nullptr) : data_(k), izq_(nullptr), der_(nullptr) {};
    ~NodoB();
    Key getData();
    NodoB* getIzq();
    NodoB* getDer();
    void setData(const Key& k);
    void setIzq(const Key& k);
    void setDer(const Key& k);
  private:
    Key data_;
    NodoB<Key>* izq_;
    NodoB<Key>* der_;
};

template<class Key>
NodoB<Key>::~NodoB() {
  izq_ = nullptr;
  der_ = nullptr;
}

template<class Key>
Key NodoB<Key>::getData() {
  return data_;
}

template<class Key>
NodoB<Key>* NodoB<Key>::getIzq() {
  return izq_;
}

template<class Key>
NodoB<Key>* NodoB<Key>::getDer() {
  return der_;
}

template<class Key>
void NodoB<Key>::setData(const Key& k) {
  data_ = k;
}

template<class Key>
void NodoB<Key>::setIzq(const Key& k) {
  izq_ = new NodoB<Key>(k);
}

template<class Key>
void NodoB<Key>::setDer(const Key& k) {
  der_ = new NodoB<Key>(k);
}

#endif // NODOB_H_