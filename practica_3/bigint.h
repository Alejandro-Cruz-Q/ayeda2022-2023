#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "number.h"

template <size_t Base>
class BigInt : public Number{
 public:
  // Constructor
  BigInt(long n = 0);
  BigInt(std::string &);
  BigInt(const char *);
  BigInt(const BigInt<Base> &);
  BigInt(const std::vector<char> &,const int & );
  // Asingment
  BigInt<Base> &operator=(const BigInt<Base> &);

  // Input/Output
  template <size_t Base_t>
  friend std::ostream &operator<<(std::ostream &, const BigInt<Base_t> &);
  template <size_t Base_t>
  friend std::istream& operator>>(std::istream&, BigInt<Base_t>&);

  // Getters and Setters
  BigInt<Base> SetSign(int);
  BigInt<Base> SetDigits(std::vector<char>);
  std::vector<char> GetDigits() const;
  int GetSign() const;

  std::string to_string() const;

  // Access
  int sign() const;
  char operator[](size_t) const;
  size_t size() const;

  //Modifications or checks
  BigInt<Base> fill_zeros(unsigned) const ;
  bool IsZero() const;
  BigInt<Base> Abs() const;
  BigInt<Base> PushBack(char);


  // Comparison
  template <size_t Base_t>
  friend bool operator==(const BigInt<Base> &, const BigInt<Base> &);
  bool operator!=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator>(const BigInt<Base> &, const BigInt<Base> &);
  bool operator>=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator<(const BigInt<Base> &, const BigInt<Base> &);
  bool operator<=(const BigInt<Base> &) const;

  // Increment/Decrement
  BigInt<Base> &operator++();    // pre-increment
  BigInt<Base> operator++(int);  // post-increment
  BigInt<Base> &operator--();    // pre-decrement
  BigInt<Base> operator--(int);  // post-decrement

  // Arithmetic
  template <size_t Base_t>
  friend BigInt<Base_t> operator+(const BigInt<Base_t> &, const BigInt<Base_t> &);

  BigInt<Base> operator-(const BigInt<Base> &) const;
  BigInt<Base> operator-() const;
  BigInt<Base> operator*(const BigInt<Base> &) const;

  template <size_t Base_t>
  friend BigInt<Base> operator/(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator%(const BigInt<Base> &) const;
  // Power
  template <size_t Base_t>
  friend BigInt<Base> pow(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator^(const BigInt<Base> &) const;

  BigInt<Base> operator!() const;

  //practica 3
  BigInt<Base>* add(const BigInt<Base>*) const override;
  BigInt<Base>* subtract(const BigInt<Base>*) const override;
  BigInt<Base>* multiply(const BigInt<Base>*) const override;
  BigInt<Base>* divide(const BigInt<Base>*) const override;
  BigInt<Base>* module(const BigInt<Base>*) const override;
  BigInt<Base>* pon(const BigInt<Base>*) const override;
  // Conversion
  operator BigInt<2>() const override;
  //operator BigInt<8>() const override;
  // operator BigInt<10>() const override;

  //static BigInt<Base>* create(size_t base, const std::string& s) override;

 protected:
  std::vector<char> digits_;
  int sign_;  // 1: positive, -1: negative
};

#include "bigint2.h"
// #include "bigint.cc"
// we need to creat template specializations for the base 2

#endif  // BIGINT_H
