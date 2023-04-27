/**
 * @file mod.cc
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
#include <ctime>

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
  SortMethod<int>* ordenacion;
  std::cout << "Introduzca el numero de elementos: ";
  std::cin >> size;
  data.resize(size);
std::cout << "Elementos seleccionados aleatoriamente\n\n";
  for (int i{0}; i < size; ++i) {
    int num;
    num = 1 + rand() % (10000 - 1000);
    data[i] = num;
  }
  unsigned t0, t1;

  t0=clock();
  std::vector<int> data1 = data;
  ordenacion = new Insertion<int>();
  ordenacion->Sort(data1, size);
  t1 = clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "Insertion Time: " << time << std::endl;

  t0 = 0;
  t1 = 0;
  data1 = data;
  ordenacion = new ShellSort<int>();
  ordenacion->Sort(data1, size);
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "ShellSort Time: " << time << std::endl;

  t0 = 0;
  t1 = 0;
  data1 = data;
  ordenacion = new HeapSort<int>();
  ordenacion->Sort(data1, size);
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "HeapSort Time: " << time << std::endl;

  t0 = 0;
  t1 = 0;
  data1 = data;
  ordenacion = new RadixSort<int>();
  ordenacion->Sort(data1, size);
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "RadixSort Time: " << time << std::endl;

  t0 = 0;
  t1 = 0;
  data1 = data;
  ordenacion = new MergeSort<int>();
  ordenacion->Sort(data1, size);
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "MergeSort Time: " << time << std::endl;

  return 0;
}

// unsigned t0, t1;
 
// t0=clock()
// // Code to execute
// t1 = clock();
 
// double time = (double(t1-t0)/CLOCKS_PER_SEC);
// cout << "Execution Time: " << time << endl;
    //   ordenacion = new Insertion<int>();
    //   ordenacion = new MergeSort<int>();
    //   ordenacion = new ShellSort<int>();
    //   ordenacion = new HeapSort<int>();
    //   ordenacion = new RadixSort<int>();