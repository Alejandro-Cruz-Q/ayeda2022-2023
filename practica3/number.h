#include "bigint.h"

class Number{
  public:
    //aritmetic operations
    virtual Number* add(const Number*) const = 0;
    virtual Number* subtract(const Number*) const = 0;
    virtual Number* multiply(const Number*) const = 0;
    virtual Number* divide(const Number*) const = 0;
    virtual Number* module(const Number*) const = 0;
    virtual Number* pow(const Number*) const = 0;
    //change of base
    virtual operator BigInt<2>() const = 0;
    virtual operator BigInt<8>() const = 0;
    virtual operator BigInt<10>() const = 0;
    virtual operator BigInt<16>() const = 0;
    //read & write
    virtual std::ostream& write(std::ostream&) const = 0;
    virtual std::istream& read(std::istream&) = 0;
    friend std::ostream& operator<<(std::ostream&, const Number&);
    friend std::istream& operator>>(std::istream&, Number&);
    //instiantation 
    static Number* create(size_t base, const string& s);
};