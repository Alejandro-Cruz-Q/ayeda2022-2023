/**
 * @file HeapSort.h
 * @author Alejandro Miguel Cruz Quiralte (Alu0101424545@ull.edu.es)
 * @brief Este algoritmo consiste en almacenar todos los elementos del vector a
 * Sort en un montículo (heap), y luego extraer el nodo que queda como nodo
 * raíz del montículo (cima) en sucesivas iteraciones obteniendo el conjunto
 * ordenado
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "SortMethod.h"

template <class Key>
class HeapSort : public SortMethod<Key> {
  public:
    void Sort(std::vector<Key>, unsigned);
    void Print(std::vector<Key> data, int size);
};

template <class Key>
void HeapSort<Key>::Sort(std::vector<Key> data, unsigned size) {
  Heap_Sort(data, size);
}

#endif  // HEAPSORT_H_