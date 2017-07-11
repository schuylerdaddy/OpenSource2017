#include<iostream>
#include<vector>

auto get_values(){
  return std::vector<int>{1,10,2,9};
}

int main(){
  std::vector<int>::iterator difficult =  get_values().begin();
  auto easy {get_values().begin()};
  std::cout<<*easy<<" "<<*difficult<<'\n';  
}
 
