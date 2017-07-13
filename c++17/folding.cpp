#include<iostream>

template<typename... T>
auto fold_sum_1(T... s){
    return (... + s);
}

int main(){
  std::cout<<fold_sum_1(1,4,7,8)<<'\n';
}