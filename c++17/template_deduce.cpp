#include<iostream>

template <typename T>   
struct Foo {
  T val;  
  Foo() : val() {}
  Foo(T val) : val(val) {}
};

int main(){
  Foo<int> c1_old{42};
  Foo c1_new{42};
}
