#include "bigint.cc"

int main(){
  BigInt<> numero1{"902"};
  BigInt<> numero2{"109"};
  // for(auto c : numero2.get_numero()){
  //   std::cout << c << ", ";
  // }
  std::cout << numero1 + numero2;
  std::cout << "\n";
  return 0;
}