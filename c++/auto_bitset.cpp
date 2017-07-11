#include<iostream>
#include<bitset>

int main(){
  std::bitset<sizeof(char)> bits;
  bits[3] = false;
  bool bit4_1 = bits[3];
  auto bit4_2 = bits[3];

  std::cout << "type of bit4_1: " << typeid(bit4_1).name() << '\n';
  std::cout << "type of bit4_2: " << typeid(bit4_2).name() << '\n';
}
