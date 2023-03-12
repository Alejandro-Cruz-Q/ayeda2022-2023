#include <iostream>
#include <ctime>


#include "bigint.h"
#include "bigint2.h"

int main() {
  // BigInt<10> y(1000000000);
  // //Test operator conversion between bases 2 to 8, 10, 16
  // BigInt<2, bool> x("1000000000");
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
  BigInt<2, char> x(1000000001);
  BigInt<2, char> y(1000000001);
  BigInt<2, bool> a(1000000001);
  BigInt<2, bool> b(1000000001); 

  unsigned t0, t1, t2, t3;
  
  t0=clock();
  x + y;
  t1 = clock();
  double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
  std::cout << "Execution Time (<2,char>): " << time1 << std::endl;
  t2=clock();
  a + b;
  t3 = clock();
  double time2 = (double(t3-t2)/CLOCKS_PER_SEC);
  std::cout << "Execution Time (<2,bool>): " << time2 << std::endl;

  return 0;
}