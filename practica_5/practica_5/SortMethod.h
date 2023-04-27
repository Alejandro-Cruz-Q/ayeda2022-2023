/**
 * @file SortMethod.h
 * @author Alejandro Miguel Cruz Quiralte (Alu0101424545@ull.edu.es)
 * @brief Esta clase abstracta es de la que se heredan el resto de clases
 * de algoritmos de ordenacion
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include <iostream>
#include <vector>

#include "Functions.h"

template<class Key>
class SortMethod {
  protected: 
    unsigned size;
    std::vector<Key> seq;
  public:
    virtual void Sort(std::vector<Key>, unsigned) = 0;
};

#endif // SORTMETHOD_H