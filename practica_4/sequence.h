#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

template <class Key>
class Sequence {
 public:
  virtual ~Sequence() {};
  virtual bool Search(Key const &k) const = 0;
  virtual bool Insert(Key const &k) = 0;
  virtual bool IsFull() const = 0;
  virtual void Print() const = 0;
};

template <class Key>
class List : public Sequence<Key> {
 public:
  List();
  ~List() override;
  bool Search(Key const &k) const override;
  bool Insert(Key const &k) override;
  bool IsFull() const override;
  void Print() const override;
 private:
  Key *list_;
  int current_sequence_size_;
  void Resize();
};

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block(int const &max_block_size);
  Block();
  ~Block() override;
  bool Search(Key const &k) const override;
  bool Insert(Key const &k) override;
  bool IsFull() const override;
  void Print() const override;
  void SetMaxSize(int max_block_size);
 private:
  Key *block_;
  int current_block_size_;
  int max_block_size_;
  void Resize();
};

/**
 * @brief Construct a new List< Key>:: List object 
 */
template <class Key>
List<Key>::List() {
  current_sequence_size_ = 0;
}

/**
 * @brief Destroy the List< Key>:: List object 
 */
template <class Key>
List<Key>::~List() {
  delete[] list_;
}

/**
 * @brief método que indica si un elemento de un tipo de dato existe en la lista.
 * @param k objeto que se va a buscar en la lista
 * @return true si el valor k del tipo Key está en la secuencia
 * @return false si el valor k del tipo Key no está en la secuencia
 */
template <class Key>
bool List<Key>::Search(Key const &k) const {
  for(int i{0}; i < current_sequence_size_; ++i) {
    if (k == list_[i]) {
      return true;
    }
  }
  return false;
}

/**
 * @brief método que permite insertar un elemento en la lista
 * @param k objeto del tipo de dato Key que se quiere insertar en la lista
 * @return true si se inserta el valor k
 * @return false si el valor ya se encontraba en la lista
 */
template <class Key>
bool List<Key>::Insert(Key const &k) {
  if (!Search(k)) {
    Resize();
    list_[current_sequence_size_ - 1] = k;
    return true;
  } 
  return false;
}

/**
 * @brief método que indica si una secuencia está llena. Como se trata de una lista, nunca va a estar llena.
 * @return true si está lleno
 * @return false si no está lleno
 */
template <class Key>
bool List<Key>::IsFull() const {
  return false;
}

/**
 * @brief método que permite imprimir por pantalla un objeto List.
 */
template <class Key>
void List<Key>::Print() const {
  for (int i{0}; i < current_sequence_size_; ++i) {
    std::cout << list_[i];
    if (i != current_sequence_size_-1) {
      std::cout << " ";
    }
  }
  //std::cout << ". Tamaño de la lista: " << current_sequence_size_;
}

/**
 * @brief método que aumenta en una unidad el tamaño del vector. 
 */
template <class Key>
void List<Key>::Resize() {
  Key *aux = new Key[current_sequence_size_ + 1];
  ++current_sequence_size_;
  for (int i{0}; i < current_sequence_size_ - 1; ++i) {
    aux[i] = list_[i];
  }
  delete[] list_;
  list_ = aux;
}

/**
 * @brief Construct a new Block< Key>:: Block object
 * @param max_block_size 
 */
template<class Key>
Block<Key>::Block(int const &max_block_size) {
  max_block_size_ = max_block_size;
  current_block_size_ = 0;
}

/**
 * @brief Construct a new Block< Key>:: Block object
 * @param max_block_size 
 */
template<class Key>
Block<Key>::Block() {
  max_block_size_ = 0;
  current_block_size_ = 0;
}

/**
 * @brief Destroy the Block< Key>:: Block object
 */
template<class Key>
Block<Key>::~Block() {
  delete[] block_;
}

/**
 * @brief método que indica si un elemento de un tipo de dato existe en el bloque.
 * @param k objeto que se va a buscar en el bloque.
 * @return true si el valor k del tipo Key está en la secuencia
 * @return false si el valor k del tipo Key no está en la secuencia
 */
template<class Key>
bool Block<Key>::Search(Key const &k) const {
  for (int i{0}; i < current_block_size_; ++i) {
    if (block_[i] == k) {
      return true;
    }
  }
  return false;
}

/**
 * @brief método que indica si el bloque está lleno.
 * @return true si está lleno
 * @return false si no está lleno
 */
template <class Key>
bool Block<Key>::IsFull() const {
  if (current_block_size_ >= max_block_size_) {
    return true;
  }
  return false;
}

/**
 * @brief método que permite insertar un elemento en la lista
 * @param k objeto del tipo de dato Key que se quiere insertar en la lista
 * @return true si se inserta el valor k
 * @return false si el valor ya se encontraba en la lista
 */
template<class Key>
bool Block<Key>::Insert(Key const &k) {
  if (!IsFull() && !Search(k)) {
    Resize();
    block_[current_block_size_ - 1] = k;
    return true;
  }
  return false;
}

/**
 * @brief método que aumenta en una unidad el tamaño del vector. 
 */
template<class Key>
void Block<Key>::Resize() {
  Key *aux = new Key[current_block_size_ + 1];
  ++current_block_size_;
  for(int i{0}; i < current_block_size_ - 1; ++i) {
    aux[i] = block_[i];
  }
  delete[] block_;
  block_ = aux;
}

/**
 * @brief método que permite imprimir por pantalla un objeto Block.
 */
template <class Key>
void Block<Key>::Print() const {
  for (int i{0}; i < current_block_size_; ++i) {
    std::cout << block_[i];
    if (i != current_block_size_-1) {
      std::cout << " ";
    }
  }
  //std::cout << ". Tamaño máximo del bloque: " << max_block_size_;
}

/**
 * @brief  
 * @param max_block_size 
 */
template<class Key>
void Block<Key>::SetMaxSize(int max_block_size) {
  max_block_size_ = max_block_size;
}

#endif