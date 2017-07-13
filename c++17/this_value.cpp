#include<iostream>

struct MyObj {
  int value{ 123 };
  auto getValueCopy() {
    return [*this] { return value; };
  }
  auto getValueRef() {
    return [this] { return value; };
  }
};

int main(){
  MyObj mo;
  auto valueCopy = mo.getValueCopy();
  auto valueRef = mo.getValueRef();
  mo.value = 321;
  valueCopy(); // 123
  valueRef(); // 321
}