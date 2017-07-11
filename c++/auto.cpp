#include<iostream>
#include<array>

int main() {
  enum {N = 3};
  
  std::array<int,N> arr{10,20,30};  
  auto elem = arr.at(2);
  std::cout<<elem<<std::endl;
}
