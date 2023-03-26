/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmo y Estructura de Datos Avanzado
  *
  * @file Clave.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 29 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase Clave.
  * @bug ningún bug conocido.
  * 
  */

#ifndef CLAVE_H
#define CLAVE_H

#include <cstdlib>
#include <iostream>

class Clave {
 public:
  Clave() {key_ = rand();}
  Clave(unsigned key) {key_ = key;}
  bool operator==(Clave const &key) {
    ++count;
    return key_ == key.key_;
  }
  operator unsigned() const {return key_;}
  static void ResetCount() {count = 0;}
  static unsigned GetCount() {return count;}
  void SetKey(unsigned key) {key_ = key;};
 private:
  unsigned key_;
  static unsigned count;
};

std::istream& operator>>(std::istream &i, Clave &key) {
  long aux;
  i >> aux;
  key.SetKey(aux);
  return i;
}

#endif