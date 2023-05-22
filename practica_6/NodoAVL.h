#pragma once

template <class Key>
class NodoAVL
{
private:
    Key dato;
    int bal;

public:
    NodoAVL<Key> *izquierdo;
    NodoAVL<Key> *derecho;

    NodoAVL(Key dato_, NodoAVL<Key> *iz = nullptr, NodoAVL<Key> *der = nullptr) : dato(dato_), bal(0), izquierdo(iz), derecho(der) {}
    ~NodoAVL() {}

    Key get_dato() { return dato; }
    int get_bal() { return bal; }
    void set_dato(Key dato_) { dato = dato_; }
    void set_bal(int bal_) { bal = bal_; }
};