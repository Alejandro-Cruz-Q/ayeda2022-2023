#include "SortMethod.h"

template <class Key>
void Print(std::vector<Key> data, int size) {
  for (int i{0}; i < size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <class Key>
void Floyd(std::vector<Key>& data, int i, int n) {
  Key cambio;
  cambio = data[i];
  int aux = 0;
  // Se van intercambiando los valores hasta que se llega a una hoja del árbol
  while ((2 * i) < n) {
    int aux1 = (2 * i + 1);
    int aux2 = aux1 + 1;
    // Se selecciona el mayor de los dos hijos
    if (aux1 == n) {
      aux = aux1;
    } else if ((aux1 < n) && (data[aux1] > data[aux2])) {
      aux = aux1;
    } else {
      aux = aux2;
    }
    // Si el padre es mayor que el mayor de los hijos, se termina el intercambio
    if (data[aux] <= cambio) {
      break;
    } else {
      // Si el hijo es mayor, se intercambian los valores
      data[i] = data[aux];
      data[aux] = cambio;
      i = aux;
    }
  }
}

template<class Key>
void Heap_Sort(std::vector<Key>& data, unsigned sizeN){
  Key cambio;
  int size = sizeN;
  // Se construye el árbol binario
  for (int i{(size / 2) - 1}; i >= 0; --i) {
    Floyd(data, i, size);
  }
  // Se extraen los valores ordenados del árbol y se ubican en el vector
  for (int i{size - 1}; i >= 0; --i) {
    // Para ver la traza
    //Print(data, size);
    // Se intercambia el primer elemento con el último
    cambio = data[0];
    data[0] = data[i];
    data[i] = cambio;
    // Se reconstruye el árbol sin el último elemento
    Floyd(data, 0, i - 1);
  }
  // Para ver la traza
  Print(data, size);
}

template<class Key>
void CountingSort(std::vector<Key>& data, int size, int exp) {
    int* output = new int[size]; // Crear un array de salida con el mismo tamaño que el array de entrada
    int* count = new int[10]; // Crear un array de conteo con 10 elementos, uno para cada dígito posible
    for (int i{0}; i < 10; i++) {
        count[i] = 0; // Inicializar el array de conteo en 0
    }
    for (int i{0}; i < size; i++) { // Contar la cantidad de ocurrencias de cada dígito en la posición actual
        count[(data[i] / exp) % 10]++;
    }
    for (int i{1}; i < 10; i++) { // Sumar los valores de conteo para obtener la posición de inicio de cada dígito en el array de salida
        count[i] += count[i - 1];
    }
    for (int i{size - 1}; i >= 0; i--) { // Colocar cada elemento en su posición correspondiente en el array de salida
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10]--;
    }
    for (int i{0}; i < size; i++) {
        data[i] = output[i]; // Copiar los elementos del array de salida de vuelta al array de entrada
    }
    delete[] output;
    delete[] count;
}

template<class Key>
void Radix_Sort(std::vector<Key>& data, unsigned size) {
  int max = data[0]; // Encontrar el valor máximo en el vector
  for (int i{1}; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  int exp = 1;
  while ((max / exp) > 0) {
    // Para ver la traza
    Print(data, size);
    CountingSort(data, size, exp); // Llamada a CountingSort para ordenar los datos según la posición de los dígitos
    exp *= 10;
  }
  // Para ver la traza
  Print(data, size);
}

template<class Key>
void deltasort(std::vector<Key>& data, int delta, int size) {
  bool flag;
  Key x;
  int j{0};
  Print(data, size);
  for (int i{delta}; i < size; i++) {
    flag = false;
    x = data[i];
    j = i;  // Se inicializa el índice j al valor de i
    while ((j >= delta) && (x < data[j - delta])){
      data[j] = data[j - delta];  // Se mueve el elemento a la posición actual
      j = j - delta;  // Se actualiza el valor del índice j
      flag = true;
      Print(data, size);
    }
    if (flag) {  // Si se ha producido algún intercambio, se inserta el valor
      data[j] = x;
      Print(data, size);
    }
  }
}

template<class Key>
void Shell_Sort(std::vector<Key>& data, unsigned size){
  float alfa;
  std::cout << "Introduzca el valor de alfa (valor entre 0 y 1): ";
  std::cin >> alfa;  
  int delta = size * alfa;  // valor inicial de delta
  while (delta > 0) {  // Se repite el proceso mientras delta sea mayor que cero
    delta = delta / 2;  // Se reduce el valor de delta a la mitad en cada iteración
    deltasort(data, delta, size);
  }
  Print(data, size);
}

template <class Key>
void merge(std::vector<Key>& seq, int ini, int mid, int fin){
  std::vector<Key> aux = seq;
  int i = ini, j = mid+1, k = ini;
  while(( i <= mid ) && ( j <= fin )){
    if(seq.at(i) < seq.at(j)){
      aux.at(k) = seq.at(i);
      i++;
    } else {
      aux.at(k) = seq.at(j);
      j++;
    }
    k++;
  } 
  if(i > mid){
    while( j <= fin ){
      aux.at(k) = seq.at(j);
      j++; 
      k++;
    }
  } else {
    while( i <= mid ){
      aux.at(k) = seq.at(i);
      i++; 
      k++;
    }
  }
  for(int k = ini; k <= fin; k++){
    seq.at(k) = aux.at(k);
  }
}

template <class Key>
void Merge_Sort(std::vector<Key>& seq, int ini, int fin){
  if( ini < fin ){
    int mid = (ini + fin)/2;
    Merge_Sort(seq, ini, mid);
    Merge_Sort(seq, mid+1, fin);
    merge(seq, ini, mid, fin);
  }
}

template<class Key>
void Insertion_Sort(std::vector<Key>& data, unsigned size){
  for(int i = 1; i < size; i++) {
    int key = data[i]; // Guardamos el elemento actual en key
    int j = i - 1;
    while(j >= 0 && data[j] > key) { // iteramos sobre los elementos anteriores y los comparamos con el actual
      data[j + 1] = data[j]; // intercambiamos las posiciones si es menor
      j--;
      }
    data[j + 1] = key; // colocamos el elemento en su posición correcta
    Print(data, size);
  }
}