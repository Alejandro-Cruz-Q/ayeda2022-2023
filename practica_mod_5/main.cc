/**
 * @file main.cc
 * @author Alejandro Miguel Cruz Quiralte (Alu0101424545@ull.edu.es)
 * @brief Programa principal para el uso de algoritmos de ordenación
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <iostream>

#include "SortMethod.h"
#include "Insertion.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "RadixSort.h"

int main() {
  std::vector<int> data;
  unsigned size;
  int opcion;
  std::cout << "Algoritmos a elegir:\n";
  std::cout << "1. Inserción\n";
  std::cout << "2. MergeSort\n";
  std::cout << "3. ShellSort\n";
  std::cout << "4. HeapSort\n";
  std::cout << "5. RadixSort\n";
  std::cout << "Introduzca una opción (entre el 1 y el 5): ";
  std::cin >> opcion;
  SortMethod<int>* ordenacion;
  switch (opcion) {
    case 1:
      ordenacion = new Insertion<int>();
      break;
    case 2:
      ordenacion = new MergeSort<int>();
      break;
    case 3:
      ordenacion = new ShellSort<int>();
      break;
    case 4:
      ordenacion = new HeapSort<int>();
      break;
    case 5:
      ordenacion = new RadixSort<int>();
      break;
    default:
      break;
  }
  std::cout << "Introduzca el numero de elementos: ";
  std::cin >> size;
  data.resize(size);
  std::cout << "Quiere introducir los elementos : (0), o se seleccionan "
               "aleatoriamente: (1) => ";
  std::cin >> opcion;
  switch (opcion) {
    case 0:
      std::cout << "Introduce " << size
                << " valores, intercalados por espacios\n";
      for (int i{0}; i < size; i++) {
        int valor;
        std::cin >> valor;
        data[i] = valor;
      }
      break;
    case 1:
      std::cout << "Elementos seleccionados aleatoriamente\n\n";
      for (int i{0}; i < size; ++i) {
        int num;
        num = 1 + rand() % (10000 - 1000);
        data[i] = num;
      }
      break;
  }

  // Ejecuto el algoritmo de odenar
  ordenacion->Sort(data, size);
  return 0;
}