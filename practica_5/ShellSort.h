/**
 * @file ShellSort.h
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

#ifndef SHELLSORT_H_ 
#define SHELLSORT_H_

#include "SortMethod.h"

template<class Key>
class ShellSort : public SortMethod<Key> {
  public:
    void Sort(std::vector<Key>, unsigned);
  private:
    float alfa_;
};

template<class Key>
void ShellSort<Key>::Sort(std::vector<Key> vec, unsigned size){
  Shell_Sort(vec, size);
}

#endif // SHELLSORT_H_