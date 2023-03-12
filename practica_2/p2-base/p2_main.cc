#include <iostream>
#include <chrono>


#include "bigint.h"
#include "bigint2.h"

int main() {
  BigInt<10> y(1000000000);
  //Test operator conversion between bases 2 to 8, 10, 16
  BigInt<2> x("1000000000");
  std::vector<bool> v = x.GetDigits();
  std::vector<char> v2 = y.GetDigits();

  std::cout << "Size of vector is: " << sizeof(v) << std::endl;
  std::cout << "Size of vector is: " << v.size() << std::endl;
  std::cout << "Size of vector is: " << v.capacity() << std::endl;

  std::cout << "Size of vector is: " << sizeof(v2) << std::endl;
  std::cout << "Size of vector is: " << v2.size() << std::endl;
  std::cout << "Size of vector is: " << v2.capacity() << std::endl;

  std::cout << "v1 = " << sizeof(v[0]) << std::endl;
  std::cout << "v2 = " << sizeof(v2[0]) << std::endl; 




  size_t sizeOfMyUser = sizeof(x);
  size_t sizeOfY = sizeof(y);
  std::cout << "Size of BigInt<2> is: " << sizeOfMyUser << std::endl;
  std::cout << "Size of BigInt<10> is: " << sizeOfY << std::endl;

  return 0;
}