/**
 * @file MergeSort.h
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

#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortMethod.h"

template<class Key>
class MergeSort : public SortMethod<Key>{
  public:
    void Sort(std::vector<Key>, unsigned size);
  private:
};

template<class Key>
void MergeSort<Key>::Sort(std::vector<Key> vec, unsigned size){
  // for(int i = 1; i < size; i++){
    Merge_Sort(vec, 0, size -1);
    // for(int i = 0; i < size; i++){
    //   std::cout << vec[i] << " ";
    // }
    // std::cout << "\n";
  }
//}

#endif // MERGESORT_H