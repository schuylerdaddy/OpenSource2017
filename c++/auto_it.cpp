#include<iostream>

int main(){
  auto val1 { 1 + 1};  
  auto val2 { 1 + 1.0};  
  auto val3 {"42"};
  auto val4 = { 1 , 1};
  auto val5 = { 'c', 'a', 't'};
 
  std::cout << "type of val1: " << typeid(val1).name() << '\n';
  std::cout << "type of val2: " << typeid(val2).name() << '\n';
  std::cout << "type of val3: " << typeid(val3).name() << '\n';
  std::cout << "type of val4: " << typeid(val4).name() << '\n';
  std::cout << "type of val5: " << typeid(val5).name() << '\n'; 
}
