#include "functions.h"

#define MAX 10000

unsigned Clave::count = 0;

int main() {
  unsigned table_size = AskingForTableSize();
  table_size = MAX;
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
  Clave Bank[MAX];
  for (int i{0}; i < MAX/2; ++i) {
    hash_table.Insert(Bank[i]);
  }
  hash_table.Print();
  Clave::ResetCount();
  int comparations;
  hash_table.Insert(28);
  hash_table.Search(28);
  std::cout << "Comparación: " << Clave::GetCount() << std::endl;
  for(int i{(MAX/2+1)}; i < MAX; ++i) {
    hash_table.Search(Bank[i]);
    comparations = Clave::GetCount();
  }
  std::cout << "Número de comparaciones hechas: " << comparations << std::endl;
  return 0;
}
