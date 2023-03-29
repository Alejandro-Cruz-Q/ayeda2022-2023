#include "functions.h"

unsigned Clave::count = 0;

int protected_main();

int main() {
  try {
    return protected_main();
  }
  catch(Exception_d &exception) {
    std::cerr << exception << std::endl;
    return exception.GetErrorCode();
  }
  catch(...) {
    std::cerr << "Error desconocido." << std::endl;
    return -1;
  }
  return 0;
}

int protected_main() {
  unsigned table_size = AskingForTableSize();
  DispersionFunction<Clave> *dispersion_f = AskingForDispersionFunction(table_size);
  ExplorationFunction<Clave> *exploration_f = nullptr;
  bool open_scatter = AskingForDispersionTechnique();
  unsigned block_size{0};
  if (!open_scatter) {
    block_size = AskingForBlockSize();
    exploration_f = AskingForExplorationFunction(table_size);
  }
  HashTable<Clave> hash_table{table_size, dispersion_f, exploration_f, block_size};
  bool flag{true};
  while (flag) {
    char aux_char = Menu(hash_table);
    if (aux_char == 'q') {
      flag = false;
    }
  }
  std::cout << "Terminando programa" << std::endl;
  return 0;
}