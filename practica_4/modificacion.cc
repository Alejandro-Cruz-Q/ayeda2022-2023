#include "functions.h"

unsigned Clave::count = 0;

int main() {
  unsigned table_size = AskingForTableSize();
  DispersionFunction<Clave> *dispersion_f = AskingForDispersionFunction(table_size);
  ExplorationFunction<Clave> *exploration_f = nullptr;
  bool open_scatter = AskingForDispersionTechnique();
  unsigned block_size{0};
  if (!open_scatter) {
    block_size = AskingForBlockSize();
    exploration_f = AskingForExplorationFunction(table_size);
  }
  srand(47);
  HashTable<Clave> hash_table{table_size, dispersion_f, exploration_f, block_size};
  Clave Bank[table_size * block_size]; // Banco de claves aleatorias
  for (int i{0}; i < (table_size * block_size)/10; ++i) {
    hash_table.Insert(Bank[i]); // Inserción del 10% de la tabla
  }
  //hash_table.Print();
  Clave::ResetCount(); // Inicializamos contador a 0
  double comparations{0};
  //std::cout << "Comparación: " << Clave::GetCount() << std::endl;
  for(unsigned int i{(table_size * block_size)/2+1}; i < table_size * block_size; ++i) {
    Clave::ResetCount(); // Inicializamos contador a 0
    hash_table.Search(Bank[i]);
    comparations += Clave::GetCount();
  }
  std::cout << "Media de comparaciones hechas con 10%: " << comparations/10 << std::endl;
  return 0;
}