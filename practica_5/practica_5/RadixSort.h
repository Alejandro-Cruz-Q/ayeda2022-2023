/**
 * @file RadixSort.h
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

#ifndef RADIXSORT_H_ 
#define RADIXSORT_H_

#include "SortMethod.h"

template<class Key>
class RadixSort : public SortMethod<Key> {
public:
  void Sort(std::vector<Key>, unsigned);
};

template<class Key>
void RadixSort<Key>::Sort(std::vector<Key> vec, unsigned size){
  Radix_Sort(vec, size);
}

#endif // RADIXSORT_H_