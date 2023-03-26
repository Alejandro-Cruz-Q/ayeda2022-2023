#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "exploration_func.h"
#include "sequence.h"
#include <vector>

template<class Key>
class HashTable {
 public:
  HashTable(unsigned const &table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe = nullptr, unsigned block_size = 0);
  ~HashTable();
  bool Search(Key const &k) const;
  bool Insert(Key const &k);
  void Print() const;
 private:
  unsigned table_size_;
  Sequence<Key> **table_;
  DispersionFunction<Key> *fd_;
  unsigned block_size_;
  ExplorationFunction<Key> *fe_;
};

/**
 * @brief Construct a new Hash Table< Key>:: Hash Table object
 * @param table_size tamaño que tendrá la tabla hash
 * @param fd puntero a un objeto del tipo DispersionFunction que representará la función de dispersión que se quiere usar.
 * @param fe 
 * @param block_size 
 */
template<class Key>
HashTable<Key>::HashTable(unsigned const &table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, unsigned block_size) {
  table_size_ = table_size;
  fd_ = fd;
  fe_ = fe;
  block_size_ = block_size;
  table_ = new Sequence<Key>*[table_size_];
  if (fe_ != nullptr && block_size_ != 0) {
    for(int i{0}; i < table_size_; ++i) {
      table_[i] = new Block<Key>(block_size_);
    }
  } else {
    for(int i{0}; i < table_size_; ++i) {
      table_[i] = new List<Key>();
    }
  }
}

/**
 * @brief Destroy the Hash Table< Key>:: Hash Table object
 */
template<class Key>
HashTable<Key>::~HashTable() {
  for(int i{0}; i < table_size_; ++i) {
    delete table_[i];
  }
  delete[] table_;
}

/**
 * @brief méteto que permite saber si una clave está en la tabla
 * @param k clave que se quiere buscar
 * @return true si está en la tabla
 * @return false no está en la tabla
 */
template<class Key>
bool HashTable<Key>::Search(Key const &k) const {
  int key_position = fd_->operator()(k);
  for(int i{0}; i < table_size_; ++i) {
    if (table_[key_position]->Search(k)) {
      return true;
    } else if (table_[key_position]->IsFull()) {
      int displacement = fe_->operator()(k,i);
      /*for (int j{0}; j < displacement; ++j) {
        ++key_position;
        if (key_position == table_size_) {
          key_position = 0;
        }
      }*/
      key_position = (key_position + displacement) % table_size_;
    } else {
      return false;
    }
  }
  return false;
}

/**
 * @brief método que permite insertar en la tabla una clave
 * @param k clave que se quiere insertar
 * @return true si la clave se pudo insertar en la tabla
 * @return false si ya estaba la clave en la tabla
 */
template<class Key>
bool HashTable<Key>::Insert(Key const &k) {
  int key_position = fd_->operator()(k);
  for(int i{0}; i < table_size_; ++i) {
    if (!table_[key_position]->Search(k) && !table_[key_position]->IsFull()) {
      table_[key_position]->Insert(k);
      return true;
    } else if (table_[key_position]->Search(k)) {
      return false;
    } else if (table_[key_position]->IsFull()) {
      int displacement = fe_->operator()(k,i);
      for (int j{0}; j < displacement; ++j) {
        ++key_position;
        if (key_position == table_size_) {
          key_position = 0;
        }
      }
    } else {
      return false;
    }
  }
  return false;
}

template<class Key>
void HashTable<Key>::Print() const {
  std::cout << "Tamaño de la tabla hash: " << table_size_ << std::endl;
  for(int i{0}; i < table_size_; ++i) {
    std::cout << "[" << i << "] -> |";
    table_[i]->Print();
    std::cout << "|" << std::endl;
  }
}

#endif