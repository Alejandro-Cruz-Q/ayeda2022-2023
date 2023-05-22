#pragma once
#include <deque>
#include "NodoAVL.h"

template <class Key>
class AVL
{
private:
    NodoAVL<Key> *raiz;

    //Operaciones iniciales
    void podar(NodoAVL<Key> *&nodo);

    //Tamano y altura
    const int size_rama(NodoAVL<Key> *nodo);
    const int altura_nodo(NodoAVL<Key> *nodo);

    //Busqueda
    NodoAVL<Key> *buscar_rama(NodoAVL<Key> *nodo, Key clave);

    //Insertar
    void insertar_bal(NodoAVL<Key> *&nodo, NodoAVL<Key> *nuevo, bool &crece);
    void insertar_re_bal_izquierda(NodoAVL<Key> *&nodo, bool &crece);
    void insertar_re_bal_derecha(NodoAVL<Key> *&nodo, bool &crece);

    //Eliminar
    void eliminar_rama(NodoAVL<Key> *&nodo, Key clave, bool &decrece);
    void eliminar_re_bal_izquierda(NodoAVL<Key> *&nodo, bool &decrece);
    void eliminar_re_bal_derecha(NodoAVL<Key> *&nodo, bool &decrece);

    //Recorridos
    void preorden(NodoAVL<Key> *nodo);
    void inorden(NodoAVL<Key> *nodo);
    void postorden(NodoAVL<Key> *nodo);
    void niveles(NodoAVL<Key> *nodo);
    void mostrar(NodoAVL<Key> *nodo);

public:
    AVL();
    ~AVL();
    bool hoja(NodoAVL<Key> *nodo);
    bool vacio(NodoAVL<Key> *nodo);

    //Tamano y altura
    const int size();
    const int altura();

    //Busqueda
    NodoAVL<Key> *buscar(Key clave);

    //Rotaciones
    void rotacion_II(NodoAVL<Key> *&nodo);
    void rotacion_DD(NodoAVL<Key> *&nodo);
    void rotacion_ID(NodoAVL<Key> *&nodo);
    void rotacion_DI(NodoAVL<Key> *&nodo);

    //Insertar
    void insertar(Key clave);

    //Eliminar
    void eliminar(Key clave);

    //Sustituir
    void sustituir(NodoAVL<Key> *&eliminado, NodoAVL<Key> *&sustituto, bool &decrece);

    //Recorridos
    void write(int recorrido);
};

template <class Key>
AVL<Key>::AVL() : raiz(nullptr)
{
}

template <class Key>
AVL<Key>::~AVL()
{
    podar(raiz);
}

template <class Key>
void AVL<Key>::podar(NodoAVL<Key> *&nodo)
{
    if (nodo == nullptr)
        return;

    podar(nodo->izquierdo);
    podar(nodo->derecho);
    delete nodo;
    nodo = nullptr;
}

template <class Key>
bool AVL<Key>::hoja(NodoAVL<Key> *nodo)
{
    return (!nodo->derecha && !nodo->izquierda);
}

template <class Key>
bool AVL<Key>::vacio(NodoAVL<Key> *nodo)
{
    return (nodo == nullptr);
}

template <class Key>
const int AVL<Key>::size()
{
    return size_rama(raiz);
}

template <class Key>
const int AVL<Key>::size_rama(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        return 0;

    return (1 + size_rama(nodo->izquierdo) + size_rama(nodo->derecho));
}

template <class Key>
const int AVL<Key>::altura()
{
    return altura_nodo(raiz);
}

template <class Key>
const int AVL<Key>::altura_nodo(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        return 0;

    int alt_izquierda = altura_nodo(nodo->izquierdo);
    int alt_derecha = altura_nodo(nodo->derecho);

    if (alt_derecha > alt_izquierda)
        return alt_derecha++;
    else
        return alt_izquierda++;
}

template <class Key>
NodoAVL<Key> *AVL<Key>::buscar(Key clave)
{
    return buscar_rama(raiz, clave);
}

template <class Key>
NodoAVL<Key> *AVL<Key>::buscar_rama(NodoAVL<Key> *nodo, Key clave)
{
    if (nodo == nullptr)
        return nullptr;

    if (clave == nodo->get_dato())
        return nodo;

    if (clave < nodo->get_dato())
        return buscar_rama(nodo->izquierdo, clave);

    return buscar_rama(nodo->derecho, clave);
}

template <class Key>
void AVL<Key>::rotacion_II(NodoAVL<Key> *&nodo)
{
    NodoAVL<Key> *nodo1 = nodo->izquierdo;
    nodo->izquierdo = nodo1->derecho;
    nodo1->derecho = nodo;

    if (nodo1->get_bal() == 1)
    {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else
    {
        nodo->set_bal(1);
        nodo1->set_bal(-1);
    }

    nodo = nodo1;
}

template <class Key>
void AVL<Key>::rotacion_DD(NodoAVL<Key> *&nodo)
{
    NodoAVL<Key> *nodo1 = nodo->derecho;
    nodo->derecho = nodo1->izquierdo;
    nodo1->izquierdo = nodo;

    if (nodo1->get_bal() == -1)
    {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else
    {
        nodo->set_bal(-1);
        nodo1->set_bal(1);
    }

    nodo = nodo1;
}

template <class Key>
void AVL<Key>::rotacion_ID(NodoAVL<Key> *&nodo)
{
    NodoAVL<Key> *nodo1 = nodo->izquierdo;
    NodoAVL<Key> *nodo2 = nodo1->derecho;

    nodo->izquierdo = nodo2->derecho;
    nodo2->derecho = nodo;
    nodo1->derecho = nodo2->izquierdo;
    nodo2->izquierdo = nodo1;

    if (nodo2->get_bal() == -1)
        nodo1->set_bal(1);
    else
        nodo1->set_bal(0);

    if (nodo2->get_bal() == 1)
        nodo->set_bal(-1);
    else
        nodo->set_bal(0);

    nodo2->set_bal(0);
    nodo = nodo2;
}

template <class Key>
void AVL<Key>::rotacion_DI(NodoAVL<Key> *&nodo)
{
    NodoAVL<Key> *nodo1 = nodo->derecho;
    NodoAVL<Key> *nodo2 = nodo1->izquierdo;

    nodo->derecho = nodo2->izquierdo;
    nodo2->izquierdo = nodo;
    nodo1->izquierdo = nodo2->derecho;
    nodo2->derecho = nodo1;

    if (nodo2->get_bal() == 1)
        nodo1->set_bal(-1);
    else
        nodo1->set_bal(0);

    if (nodo2->get_bal() == -1)
        nodo->set_bal(1);
    else
        nodo->set_bal(0);

    nodo2->set_bal(0);
    nodo = nodo2;
}

template <class Key>
void AVL<Key>::insertar(Key clave)
{
    if (buscar(clave))
        return;

    NodoAVL<Key> *nuevo = new NodoAVL<Key>(clave);
    bool crece = false;
    insertar_bal(raiz, nuevo, crece);
}

template <class Key>
void AVL<Key>::insertar_bal(NodoAVL<Key> *&nodo, NodoAVL<Key> *nuevo, bool &crece)
{
    if (nodo == nullptr)
    {
        nodo = nuevo;
        crece = true;
    }
    else if (nuevo->get_dato() < nodo->get_dato())
    {
        insertar_bal(nodo->izquierdo, nuevo, crece);
        if (crece)
            insertar_re_bal_izquierda(nodo, crece);
    }
    else
    {
        insertar_bal(nodo->derecho, nuevo, crece);
        if (crece)
            insertar_re_bal_derecha(nodo, crece);
    }
}

template <class Key>
void AVL<Key>::insertar_re_bal_izquierda(NodoAVL<Key> *&nodo, bool &crece)
{
    NodoAVL<Key> *nodo1;
    switch (nodo->get_bal())
    {
    case -1:
        nodo->set_bal(0);
        crece = false;
        break;

    case 0:
        nodo->set_bal(1);
        break;
    case 1:
        nodo1 = nodo->izquierdo;
        if (nodo1->get_bal() == 1)
            rotacion_II(nodo);
        else
            rotacion_ID(nodo);
        crece = false;
        break;
    }
}

template <class Key>
void AVL<Key>::insertar_re_bal_derecha(NodoAVL<Key> *&nodo, bool &crece)
{
    NodoAVL<Key> *nodo1;
    switch (nodo->get_bal())
    {
    case 1:
        nodo->set_bal(0);
        crece = false;
        break;
    case 0:
        nodo->set_bal(-1);
        break;
    case -1:
        nodo1 = nodo->derecho;
        if (nodo1->get_bal() == -1)
            rotacion_DD(nodo);
        else
            rotacion_DI(nodo);
        crece = false;
        break;
    }
}

template <class Key>
void AVL<Key>::eliminar(Key clave)
{
    bool decrece = false;
    eliminar_rama(raiz, clave, decrece);
}

template <class Key>
void AVL<Key>::eliminar_rama(NodoAVL<Key> *&nodo, Key clave, bool &decrece)
{
    if (nodo == nullptr)
        return;
    if (clave < nodo->get_dato())
    {
        eliminar_rama(nodo->izquierdo, clave, decrece);
        if (decrece)
            eliminar_re_bal_izquierda(nodo, decrece);
    }
    else if (clave > nodo->get_dato())
    {
        eliminar_rama(nodo->derecho, clave, decrece);
        if (decrece)
            eliminar_re_bal_derecha(nodo, decrece);
    }
    else
    {
        NodoAVL<Key> *eliminado = nodo;
        if (nodo->izquierdo == nullptr)
        {
            nodo = nodo->derecho;
            decrece = true;
        }
        else if (nodo->derecho == nullptr)
        {
            nodo = nodo->izquierdo;
            decrece = true;
        }
        else
        {
            sustituir(eliminado, nodo->izquierdo, decrece);
            if (decrece)
                eliminar_re_bal_izquierda(nodo, decrece);
        }

        delete eliminado;
    }
}

template <class Key>
void AVL<Key>::eliminar_re_bal_izquierda(NodoAVL<Key> *&nodo, bool &decrece)
{
    NodoAVL<Key> *nodo1;
    switch (nodo->get_bal())
    {
    case -1:
        nodo1 = nodo->derecho;
        if (nodo1->get_bal() > 0)
            rotacion_DI(nodo);
        else
        {
            if (nodo1->get_bal() == 0)
                decrece = false;
            rotacion_DD(nodo);
        }
        break;

    case 0:
        nodo->set_bal(-1);
        decrece = false;
        break;
    case 1:
        nodo->set_bal(0);
        break;
    }
}

template <class Key>
void AVL<Key>::eliminar_re_bal_derecha(NodoAVL<Key> *&nodo, bool &decrece)
{
    NodoAVL<Key> *nodo1;
    switch (nodo->get_bal())
    {
    case 1:
        nodo1 = nodo->izquierdo;
        if (nodo->get_bal() < 0)
            rotacion_ID(nodo);
        else
        {
            if (nodo1->get_bal() == 0)
                decrece = false;
            rotacion_II(nodo);
        }
        break;

    case 0:
        nodo->set_bal(1);
        decrece = false;
        break;

    case -1:
        nodo->set_bal(0);
        break;
    }
}

template <class Key>
void AVL<Key>::sustituir(NodoAVL<Key> *&eliminado, NodoAVL<Key> *&sustituto, bool &decrece)
{
    if (sustituto->derecho != nullptr)
    {
        sustituir(eliminado, sustituto->derecho, decrece);
        if (decrece)
            eliminar_re_bal_derecha(sustituto, decrece);
    }
    else
    {
        eliminado->set_dato(sustituto->get_dato());
        eliminado = sustituto;
        sustituto = sustituto->izquierdo;
        decrece = true;
    }
}

template <class Key>
void AVL<Key>::inorden(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        return;

    inorden(nodo->izquierdo);
    std::cout << "[";
    nodo->get_dato().write();
    std::cout << "]";
    inorden(nodo->derecho);
}

template <class Key>
void AVL<Key>::preorden(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        return;

    std::cout << "[";
    nodo->get_dato().write();
    std::cout << "]";
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

template <class Key>
void AVL<Key>::postorden(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        return;

    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    std::cout << "[";
    nodo->get_dato().write();
    std::cout << "]";
}

template <class Key>
void AVL<Key>::niveles(NodoAVL<Key> *nodo)
{
    std::deque<std::pair<NodoAVL<Key> *, int>> Q;
    NodoAVL<Key> *aux;
    int nivel = 0, nivel_actual = 0;

    Q.push_back(std::pair<NodoAVL<Key> *, int>(nodo, 0));

    std::cout << "\nNivel 0: ";

    while (!Q.empty())
    {
        aux = (Q.front()).first;
        nivel = (Q.front()).second;
        Q.pop_front();

        if (nivel > nivel_actual)
        {
            nivel_actual = nivel;
            std::cout << "\nNivel " << nivel_actual << ": ";
        }

        mostrar(aux);
        if (aux != nullptr)
        {
            Q.push_back(std::pair<NodoAVL<Key> *, int>(aux->izquierdo, nivel + 1));
            Q.push_back(std::pair<NodoAVL<Key> *, int>(aux->derecho, nivel + 1));
        }
    }
}

template <class Key>
void AVL<Key>::mostrar(NodoAVL<Key> *nodo)
{
    if (nodo == nullptr)
        std::cout << "[.]";
    else
    {
        std::cout << "[";
        nodo->get_dato().write();
        std::cout << "]";
    }
}

template <class Key>
void AVL<Key>::write(int recorrido)
{
    if (recorrido == 1)
        preorden(raiz);
    else if (recorrido == 2)
        inorden(raiz);
    else if (recorrido == 3)
        postorden(raiz);
    else
        niveles(raiz);
}