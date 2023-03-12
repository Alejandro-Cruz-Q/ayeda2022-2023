#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>


template <size_t Base = 10>
class BigInt{
  public:
  //constructores
    BigInt(long n = 0);
    BigInt(std::string& numero);
    BigInt(const char* numero);
    BigInt(const BigInt<Base>& bigint); // Constructor de copia
  //getters
    std::vector<char> get_numero() const {return numero_;};
    int longt() const {return long_;};
  //asignacion
    BigInt<Base>& operator=(const BigInt<Base>& bigint);
  //insercion extraccion
    friend std::ostream& operator<<(std::ostream& out, const BigInt<Base>& bigint){
      for(auto c : bigint.get_numero()){
        out << c << " ";
      }
      return out;
    }

    friend std::istream& operator>>(std::istream& in, BigInt<Base>& bigint){
      std::string cifra;
      in >> cifra;
      bigint = BigInt<Base>{cifra};
      return in;
    }
  //accesor
    int sign() const {return sign_;} // Signo: 1 o -1
    void set_sign(int i){
      sign_ = i;
    }
    char operator[](int i) const {return get_numero()[i];} // Acceso al i-ésimo dígito
  //comparación
    friend bool operator==(const BigInt<Base>& num1, const BigInt<Base> &num2){
      if(num1.sign() != num2.sign()) return false;
      if(num1.longt() != num2.longt()) return false;
      for(int i = 0; i < num1.longt(); ++i){
        if(num1.get_numero()[i] != num2.get_numero()[i]) return false;
      }
      return true;
    }
    bool operator!=(const BigInt<Base>& n) const {return !(this == n);}

    friend bool operator>(const BigInt<Base>& num1, const BigInt<Base> &num2){
      if(num1.sign() == false && num2.sign() == true) return false;
      if(num1.longt() < num2.longt()) return false;
      for(int i = 0; i < num1.longt(); ++i){
        if(num1[i] < num2[i]) return false;
      }
      return true;
    }

    bool operator>=(const BigInt<Base> &num) const{
      return (this > num) || (this == num);
    }

    friend bool operator<(const BigInt<Base>& num1, const BigInt<Base>& num2){
      if(num2.sign() == false && num1.sign() == true) return false;
      if(num1.longt() > num2.longt()) return false;
      for(int i = 0; i < num1.longt(); ++i){
        if(num1[i] > num2[i]) return false;
      }
      return true;
    }
    bool operator<=(const BigInt<Base>& num) const{
      return (this < num) || (this == num);
    }
  //incremento/decremento
    // BigInt<Base>& operator++(); // Pre-incremento
    // BigInt<Base> operator++(int); // Post-incremento
    // BigInt<Base>& operator--(); // Pre-decremento
    // BigInt<Base> operator--(int); // Post-decremento
  //operadores aritmeticos
  friend BigInt<Base> operator+(const BigInt<Base>& num1, const BigInt<Base>& num2){
    BigInt<Base> resultado;
    if(num1.sign_ == 1 && num2.sign_ == 1){
      resultado.sign_ = 1;
      if(num1.longt() > num2.longt()){
        resultado.long_ = num1.longt();
      }
      else{
        resultado.long_ = num2.longt();
      }
      int acarreo = 0;
      for(int i = 0; i < resultado.longt(); i++){
        int suma = num1.get_numero()[i] + num2.get_numero()[i] + acarreo;
        if(suma >= Base){
          acarreo = 1;
          suma = suma - Base;
        }
        else{
          acarreo = 0;
        }
        resultado.get_numero().push_back(suma);
      }
    }
    else if(num1.sign_ == -1 && num2.sign_ == -1){
      resultado.sign_ = -1;
      if(num1.longt() > num2.longt()){
        resultado.long_ = num1.longt();
      }
      else{
        resultado.long_ = num2.longt();
      }
      int acarreo = 0;
      for(int i = 0; i < resultado.longt(); i++){
        int suma = num1.get_numero()[i] + num2.get_numero()[i] + acarreo;
        if(suma >= Base){
          acarreo = 1;
          suma = suma - Base;
        }
        else{
          acarreo = 0;
        }
        resultado.get_numero().push_back(suma);
      }
    }
    else if(num1.sign_ == 1 && num2.sign_ == -1){
      if(num1.longt() > num2.longt()){
        resultado.long_ = num1.longt();
      }
      else{
        resultado.long_ = num2.longt();
      }
      int acarreo = 0;
      for(int i = 0; i < resultado.longt(); i++){
        int suma = num1.get_numero()[i] + num2.get_numero()[i] + acarreo;
        if(suma >= Base){
          acarreo = 1;
          suma = suma - Base;
        }
        else{
          acarreo = 0;
        }
        resultado.get_numero().push_back(suma);
      }
    }
    else if(num1.sign_ == -1 && num2.sign_ == 1){
      if(num1.longt() > num2.longt()){
        resultado.long_ = num1.longt();
      }
      else{
        resultado.long_ = num2.longt();
      }
      int acarreo = 0;
      for(int i = 0; i < resultado.longt(); i++){
        int suma = num1.get_numero()[i] + num2.get_numero()[i] + acarreo;
        if(suma >= Base){
          acarreo = 1;
          suma = suma - Base;
        }
        else{
          acarreo = 0;
        }
        resultado.get_numero().push_back(suma);
      }
    }
    return resultado;
  }

    BigInt<Base> operator-(const BigInt<Base> &num) const{
      num.set_sign(num.sign_ * -1);
      return this + num;
    }
    BigInt<Base> operator-() const{
      this.set_sign(this.sign_ * -1);
      return this;
    }
    BigInt<Base> operator*(const BigInt<Base>&num) const{
      
    }
    // friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
    // BigInt<Base> operator%(const BigInt<Base>&) const;
    // Potencia a^b
    //friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);
  private:
    int long_;
    std::vector<char> numero_;
    int sign_;
};

template <size_t Base>
BigInt<Base>::BigInt(long n){
  std::vector<char> vector(n);
  numero_ = vector;
  long_ = n;
  sign_ = 1;
}

template <size_t Base>
BigInt<Base>::BigInt(std::string& numero){
  if(numero[0] == '-'){
    sign_ = -1;
    numero.erase(0,1);
  }else if(numero[0] == '+'){
    sign_ = 1;
    numero.erase(0,1);
  }else sign_ = 1;
  for(char c : numero) {
    numero_.push_back(c);
  }
  long_ = numero_.size();
}

template <size_t Base>
BigInt<Base>::BigInt(const char* numero){
  if(numero[0] == '-'){
    sign_ = -1;
    numero++;
  }else if(numero[0] == '+'){
    sign_ = 1;
    numero++;
  }else sign_ = 1;
  int length = strlen(numero);
    for(int i = 0; i < length; i++) {
      numero_.push_back(numero[i]);
    }
  long_ = numero_.size();
}

template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base>& bigint){
  numero_ = bigint.get_numero();
  long_ = bigint.longt();
}

template <size_t Base>
BigInt<Base>& BigInt<Base>::operator=(const BigInt<Base>& bigint){
  numero_ = bigint.get_numero();
  long_ = bigint.longt();
  sign_ = bigint.sign();
}
