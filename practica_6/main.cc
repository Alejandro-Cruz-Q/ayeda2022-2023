#include "AB.h"
#include "ABE.h"
#include <iostream>

int main() {
  AB<int>* ab = new ABE<int>();
  int option;
  while (option != 0) {
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar clave" << std::endl;
    std::cout << "[2] Buscar clave" << std::endl;
    std::cout << "[3] Mostrar árbol inorden" << std::endl;
    std::cout << "Inserte opción: ";
    std::cin >> option;
    if (option == 1) {
      int key;
      std::cout << "Introduzca clave a introducir: ";
      std::cin >> key;
      if (ab->insert(key)) {
        std::cout << "Clave insertada";
        std::cout << ab;
      } else {
        std::cout << "Clave ya existente" << std::endl;
      }
      std::cout << std::endl;
    }
    
    if (option == 2) {
      int key;
      std::cout << "Introduzca clave a buscar: ";
      std::cin >> key;
      if (ab->search(key)) {
        std::cout << "Clave encontrada" << std::endl;
      } else {
        std::cout << "Clave no encontrada" << std::endl;
      }
      std::cout << std::endl;
    }
    if (option == 3) {
      ab->inOrden(ab->getRaiz());
      std::cout << std::endl << std::endl;
    }
  }
  return 0;
}