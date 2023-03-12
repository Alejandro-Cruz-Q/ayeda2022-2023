#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

template <size_t Base, class T = char>
class BigInt {
 public:
  // Constructor
  BigInt(long n = 0);
  BigInt(std::string &);
  BigInt(const char *);
  BigInt(const BigInt<Base, T> &);
  BigInt(const std::vector<char> &,const int & );
  // Conversion
  explicit operator BigInt<2>();
  

  // Asingment
  BigInt<Base, T> &operator=(const BigInt<Base, T> &);

  // Input/Output
  template <size_t Base_t>
  friend std::ostream &operator<<(std::ostream &, const BigInt<Base_t> &);
  template <size_t Base_t>
  friend std::istream& operator>>(std::istream&, BigInt<Base_t>&);

  // Getters and Setters
  BigInt<Base, T> SetSign(int);
  BigInt<Base, T> SetDigits(std::vector<char>);
  std::vector<char> GetDigits() const;
  int GetSign() const;

  std::string to_string() const;

  // Access
  int sign() const;
  char operator[](size_t) const;
  size_t size() const;

  //Modifications or checks
  BigInt<Base, T> fill_zeros(unsigned) const ;
  bool IsZero() const;
  BigInt<Base, T> Abs() const;
  BigInt<Base, T> PushBack(char);


  // Comparison
  template <size_t Base_t>
  friend bool operator==(const BigInt<Base, T> &, const BigInt<Base, T> &);

  bool operator!=(const BigInt<Base, T> &) const;
  template <size_t Base_t>
  friend bool operator>(const BigInt<Base, T> &, const BigInt<Base, T> &);
  bool operator>=(const BigInt<Base, T> &) const;
  template <size_t Base_t>
  friend bool operator<(const BigInt<Base, T> &, const BigInt<Base, T> &);
  bool operator<=(const BigInt<Base, T> &) const;

  // Increment/Decrement
  BigInt<Base, T> &operator++();    // pre-increment
  BigInt<Base, T> operator++(int);  // post-increment
  BigInt<Base, T> &operator--();    // pre-decrement
  BigInt<Base, T> operator--(int);  // post-decrement

  // Arithmetic
  template <size_t Base_t>
  friend BigInt<Base_t> operator+(const BigInt<Base_t> &, const BigInt<Base_t> &);

  BigInt<Base, T> operator-(const BigInt<Base, T> &) const;
  BigInt<Base, T> operator-() const;
  BigInt<Base, T> operator*(const BigInt<Base, T> &) const;

  template <size_t Base_t>
  friend BigInt<Base, T> operator/(const BigInt<Base, T> &, const BigInt<Base, T> &);
  BigInt<Base, T> operator%(const BigInt<Base, T> &) const;
  // Power
  template <size_t Base_t>
  friend BigInt<Base, T> pow(const BigInt<Base, T> &, const BigInt<Base, T> &);
  BigInt<Base, T> operator^(const BigInt<Base, T> &) const;

  BigInt<Base, T> operator!() const;

 private:
  std::vector<T> digits_;
  int sign_;  // 1: positive, -1: negative
};

#include "bigint2.h"
#include "bigint.cc"
// we need to creat template specializations for the base 2

#endif  // BIGINT_H