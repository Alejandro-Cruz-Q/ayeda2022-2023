// This file will be used to implement the class BigInt2
// that will be used to store binary numbers in a vector of bool
// The class BigInt2 will be a template class specialized for the base 2

#ifndef BIGINT2_H
#define BIGINT2_H
// we need to include the class BigInt to use it as a base class

#include <algorithm>
#include <cmath>
#include <vector>

#include "bigint.h"

template <>
class BigInt<2, bool> {
 public:
  BigInt(long number_x = 0);
  BigInt(const BigInt<2, bool> &other);
  BigInt(std::vector<bool> digits);
  BigInt(const std::vector<char> &,const int & );
  BigInt(std::string number_x);
  BigInt operator=(const BigInt<2, bool> &other);

  // Conversion
  template <size_t base>
 explicit operator BigInt<base>() const;

  // Getters and Setters
  std::vector<bool> GetDigits() const;
  BigInt<2, bool> SetDigits(std::vector<bool> digits);

  bool operator[](size_t) const;
  size_t size() const;
  void push_back(bool digit);

  // Modifications or checks
  bool IsZero() const;
  BigInt<2, bool> Abs() const;

  //factorial
  BigInt<2, bool> factorial() const;
  BigInt<2, bool> operator!() const;

  friend bool operator==(const BigInt<2, bool> &, const BigInt<2, bool> &);
  // Comparison operators
  bool operator!=(const BigInt<2, bool> &other) const;
  friend bool operator>(const BigInt<2, bool> &, const BigInt<2, bool> &);
  bool operator>=(const BigInt<2, bool> &other) const;
  friend bool operator<(const BigInt<2, bool> &, const BigInt<2, bool> &);
  bool operator<=(const BigInt<2, bool> &other) const;

  // Increment/Decrement
  BigInt<2, bool> &operator++();    // pre-increment
  BigInt<2, bool> operator++(int);  // post-increment
  BigInt<2, bool> &operator--();    // pre-decrement
  BigInt<2, bool> operator--(int);  // post-decrement

  // arithmetic operators
  friend BigInt<2, bool> operator+(const BigInt<2, bool> &first, const BigInt<2, bool> &other);
  BigInt<2, bool> sum_overflow(const BigInt<2, bool> &first, const BigInt<2, bool> &other) const;
  BigInt<2, bool> operator-() const;
  BigInt<2, bool> operator-(const BigInt<2, bool> &other) const;
  BigInt<2, bool> operator*(const BigInt<2, bool> &other) const;
  friend BigInt<2, bool> operator/(const BigInt<2, bool> &first, const BigInt<2, bool> &other);
  BigInt<2, bool> operator%(const BigInt<2, bool> &other) const;

  friend BigInt<2, bool> pow(const BigInt<2, bool> &first, const BigInt<2, bool> &other);
  BigInt<2, bool> operator^(const BigInt<2, bool> &other) const;

  // Displacement operators
  void operator<<(size_t n);
  void operator>>(size_t n);

  // Controlled operators
  BigInt<2, bool> FillSign(size_t n) const;
  BigInt<2, bool> ConvertToTwosComplement() const;

  // Input/Output
  friend std::ostream &operator<<(std::ostream &os, const BigInt<2, bool> &number_x);

  std::string to_string() const;

 private:
  void operator<<(BigInt<2, bool> &other);
  void operator>>(BigInt<2, bool> &other);

  std::vector<bool> digits;
};
#include "bigint2.cc"

#endif  // BIGINT2_H