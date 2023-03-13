#include <iostream>
#include <chrono>


#include "bigint.h"
#include "bigint2.h"

int main() {
  // BigInt<10> y(1000000000);
  // //Test operator conversion between bases 2 to 8, 10, 16
  // BigInt<2> x("1000000000");
  // std::vector<bool> v = x.GetDigits();
  // std::vector<char> v2 = y.GetDigits();

  // std::cout << "Size of vector is: " << sizeof(v) << std::endl;
  // std::cout << "Size of vector is: " << v.size() << std::endl;
  // std::cout << "Size of vector is: " << v.capacity() << std::endl;

  // std::cout << "Size of vector is: " << sizeof(v2) << std::endl;
  // std::cout << "Size of vector is: " << v2.size() << std::endl;
  // std::cout << "Size of vector is: " << v2.capacity() << std::endl;

  // std::cout << "v1 = " << sizeof(v[0]) << std::endl;
  // std::cout << "v2 = " << sizeof(v2[0]) << std::endl; 

  // size_t sizeOfMyUser = sizeof(x);
  // size_t sizeOfY = sizeof(y);
  // std::cout << "Size of BigInt<2> is: " << sizeOfMyUser << std::endl;
  // std::cout << "Size of BigInt<10> is: " << sizeOfY << std::endl;

  BigInt<10> x(100);
  BigInt<10> y(20);
  BigInt<10>* ptry = &y;
  BigInt<10>* ptr_result = x.add(ptry);
  BigInt<10> result = *ptr_result;
  std::cout << result << std::endl;
  BigInt<10>* ptr_result2 = x.subtract(ptry);
  BigInt<10> result2 = *ptr_result2;
  std::cout << result2 << std::endl;
  return 0;
}