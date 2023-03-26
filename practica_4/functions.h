#include <iostream>
#include <cstdlib>
#include "hashtable.h"
#include "errorManagerClass.h"
#include "Clave.h"
#include <vector>

/**
 * @brief función que compruba si una string está compuesta solo por números
 * @param string cadena de caracteres que se quiere conocer si está compuesta por caracteres
 * @return true si son solo números
 * @return false si no son solo números
 */
bool CheckIsANumber(std::string const &string) {
  if (string.size() == 0) {
    return false;
  }
  for (unsigned i{0}; i < string.size(); ++i) {
    if (i == 0 && string[i] == 45 && string.size() != 1) {

    } else if (string[i] < 40 || string [i] > 57) {
      return false;
    }
  }
  return true;
}

/**
 * @brief función que convierte una string en un número entero
 * @param string 
 * @return int 
 */
inline long IntConverter(std::string const &string) {
  if(CheckIsANumber(string)) {
    return std::stol(string);
  }
  return -1;
}

/**
 * @brief función que pide al usuario el tamaño de la tabla hash y se asegura que sea correcta. 
 */
unsigned AskingForTableSize() {
  unsigned table_size{0};
  while (table_size <= 0) {
    std::string aux_string;
    std::cout << "Introduzca el tamaño que desea que tenga la tabla hash: ";
    std::cin >> aux_string;
    if (CheckIsANumber(aux_string)) {
      table_size = IntConverter(aux_string);
    }
    if (table_size <= 0) {
      std::cerr << "functions.cc 45: el tamaño de la tabla tiene que ser un número mayor que 0." << std::endl;
    }
  }
  return table_size;
}

/**
 * @brief función que comprueba si una opción es valida
 * @param option_selected opcion que fue escogida
 * @param valids_options vector con las opciones que son consideradas validas
 * @return true si la opción escogida es válida
 * @return false si la opción escogida no es válida
 */
bool OptionItsValid(std::string const &option_selected, std::vector<std::string> const &valids_options) {
  for (unsigned i{0}; i < valids_options.size(); ++i) {
    if (valids_options[i] == option_selected) {
      return true;
    }
  }
  return false;
}

/**
 * @brief función que devuelve el tipo de función de dispersión elegido por el usuario
 * @param table_size 
 * @return DispersionFunction<Clave>* 
 */
DispersionFunction<Clave>* AskingForDispersionFunction(int const &table_size) {
  std::string dispersion_option;
  std::vector<std::string> valid_options {"a", "b", "c"};
  DispersionFunction<Clave> *dispersion_function;
  bool flag{true};
  while (flag) {
    std::cout << "De las siguientes funciones de dispersión, seleccione la que desea que se aplique: " << std::endl;
    std::cout << "a) Función de dispersión Módulo." << std::endl;
    std::cout << "b) Función de dispersión Basada en suma." << std::endl;
    std::cout << "c) Función de dispersión Pseudoaleatoria." << std::endl;
    std::cin >> dispersion_option;
    if (OptionItsValid(dispersion_option, valid_options)) {
      flag = false;
    } else {
      std::cerr << "functions.cc 104: opción no válida. Intente de nuevo" << std::endl;
    }
  }
  switch (dispersion_option[0]) {
    case 'a':
      dispersion_function = new FDModule<Clave>(table_size);
      std::cout << "Función escogida: modulo." << std::endl;
      break;
    case 'b':
      dispersion_function = new FDBasedOnSum<Clave>(table_size);
      std::cout << "Función escogida: basada en suma." << std::endl;
      break;
    case 'c':
      dispersion_function = new FDPseudorandom<Clave>(table_size);
      std::cout << "Función escogida: pseudoaleatoria." << std::endl;
      break;
  default:
      break;
  }
  return dispersion_function;
}

bool AskingForDispersionTechnique() {
  std::string dispersion_technique_option;
  std::vector<std::string> valid_options {"a", "b"};
  bool flag{true};
  while (flag) {
    std::cout << "Ahora escoja que técnica de dispersión desea:" << std::endl;
    std::cout << "a) Cerrada" << std::endl;
    std::cout << "b) Abierta" << std::endl;
    std::cin >> dispersion_technique_option;
    if(OptionItsValid(dispersion_technique_option, valid_options)) {
      flag = false;
    } else {
      std::cerr << "functions.cc 135: opción no válida. Intente de nuevo" << std::endl;
    }
  }
  if (dispersion_technique_option[0] == 'a') {
    return false;
  }
  return true;
}

/**
 * @brief función que pide al usuario el tamaño del bloque en caso de que se trate de dispersion cerrada y se asegura que sea correcta. 
 */
unsigned AskingForBlockSize() {
  unsigned block_size{0};
  while (block_size <= 0) {
    std::string aux_string;
    std::cout << "Introduzca el tamaño que desea que tenga los bloques: ";
    std::cin >> aux_string;
    if (CheckIsANumber(aux_string)) {
      block_size = IntConverter(aux_string);
    }
    if (block_size <= 0) {
      std::cerr << "functions.cc 45: el tamaño de los bloques tiene que ser un número mayor que 0." << std::endl;
    }
  }
  return block_size;
}

/**
 * @brief función que devuelve el tipo de función de exploración elegida por el usuario
 * @param table_size 
 * @return ExplorationFunctionFunction<Clave>* 
 */
ExplorationFunction<Clave>* AskingForExplorationFunction(int const &table_size) {
  std::string exploration_option;
  std::vector<std::string> valid_options {"a", "b", "c", "d"};
  ExplorationFunction<Clave> *exploration_function;
  bool flag{true};
  while (flag) {
    std::cout << "De las siguientes funciones de exploración, seleccione la que desea que se aplique a su tabal hash: " << std::endl;
    std::cout << "a) Función de exploración Lineal." << std::endl;
    std::cout << "b) Función de exploración Cuadrática." << std::endl;
    std::cout << "c) Función de exploración Doble Dispersión." << std::endl;
    std::cout << "d) Función de exploración Redispersión." << std::endl;
    std::cin >> exploration_option;
    if (OptionItsValid(exploration_option, valid_options)) {
      flag = false;
    } else {
      std::cerr << "functions.cc 104: opción no válida. Intente de nuevo." << std::endl;
    }
  }
  switch (exploration_option[0]) {
    case 'a':
      exploration_function = new EFLineal<Clave>();
      std::cout << "Función escogida: lineal." << std::endl;
      break;
    case 'b':
      exploration_function = new EFQuadratic<Clave>();
      std::cout << "Función escogida: cuadrática." << std::endl;
      break;
    case 'c':
      std::cout << "Función escogida: doble dispersion." << std::endl;
      exploration_function = new EFDoubleScatter<Clave>(AskingForDispersionFunction(table_size));
      break;
    case 'd':
      exploration_function = new EFRedispersion<Clave>();
      std::cout << "Funcion escogida: redispersion." << std::endl;
  default:
      break;
  }
  return exploration_function;
}

/**
 * @brief función que permite la insersión de claves dentro de la tabla hash
 * @param hash_table tabla hash donde se van a insertar las claves
 */
void InsertKey(HashTable<Clave> &hash_table) {
  std::string user_input;
  std::cout << "Ingrese las claves númericas que desea añadir a la tabla hash. Inserte ~q~ cuando haya finalizado de ingresar claves: " << std::endl;
  while (user_input != "q") {
    std::cout << "Ingrese clave númerica: ";
    std::cin >> user_input;
    if (CheckIsANumber(user_input)) {
      hash_table.Insert(IntConverter(user_input));
    } else {
      std::cout << "Clave no válida" << std::endl;
    }
  }
}

/**
 * @brief función que permite identificar si una clave se encuentra en la tabla hash.
 * @param hash_table 
 */
void SearchKey(HashTable<Clave> const &hash_table) {
  std::string user_input;
  std::cout << "Ingrese las claves númericas que desea buscar en la tabla hash. Inserte ~q~ para terminar el proceso de búsqueda: " << std::endl;
  while (user_input != "q") {
    std::cout << "Ingrese clave númerica a buscar: ";
    std::cin >> user_input;
    if (CheckIsANumber(user_input)) {
      if(hash_table.Search(IntConverter(user_input))) {
        std::cout << "La clave " << user_input << " si se encuentra dentro de la tabla hash" << std::endl;
      } else {
        std::cout << "La clave " << user_input << " no se encuentra dentro de la tabla hash" << std::endl;
      }
    } else {
      std::cout << "Clave no válida" << std::endl;
    }
  }
}

/**
 * @brief menú del programa HashTable_ClientProgram.
 * @param hash_table 
 */
char Menu(HashTable<Clave> &hash_table) {
  std::string option;
  std::vector<std::string> valids_options{"a", "b", "c", "q"};
  bool flag{true};
  while (flag) {
    std::cout << "Elija que operación desea realizar: " << std::endl;
    std::cout << "a) Insertar claves en la tabla hash." << std::endl;
    std::cout << "b) Buscar claves en la tabla hash." << std::endl;
    std::cout << "c) Mostrar tabla hash." << std::endl;
    std::cout << "q) Salir." << std::endl;
    std::cin >> option;
    if (OptionItsValid(option, valids_options)) {
      flag = false;
    } else {
      std::cerr << "functions.cc 223: opción no válida. Intente de nuevo." << std::endl;    
    }
  }
  switch (option[0]) {
  case 'a':
    InsertKey(hash_table);
    return 'a';
    break;

  case 'b':
    SearchKey(hash_table);
    return 'b';
    break;

  case 'c':
    hash_table.Print();
    return 'c';
    break;

  case 'q':
    return 'q';
    break;

  default:
    return 'q';
    break;
  }

}