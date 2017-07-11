#include <iostream>
#include <string>
using namespace std;

struct wrapper{
  char* data = nullptr;
  int size;
  wrapper(int sz){
    size = sz;
    data = new char[size];
    std::cout << "<ctor> allocated " << sz << " bytes\n";
  }
  wrapper(const wrapper& wr){
    this->size = wr.size;
    this->data = new char[size];
    std::cout << "<copy ctor> allocated " << size << " bytes\n";
    for (int i = 0; i<size; ++i){
    std:cout << "<copy ctor> copying " << wr.data[i] << "\n";
      this->data[i] = wr.data[i];
    }
  }

  wrapper(wrapper&& wr){
    std::cout << "<move ctor> swaping pointers..\n";
    this->size = wr.size;
    auto t = wr.data;
    wr.data = this->data;
    this->data = t;
  }
  ~wrapper(){
    if (data){
      delete[] data;
      std::cout << "<dtor> destructor deallocating " << size << " bytes\n";
    }
    else{
      std::cout << "<dtor> destructor noop\n";
    }
  }
};

wrapper factory(int i){
  std::cout << "<factory> generating wrapper of " << i << " btyes\n";
  auto wt = wrapper(i);
  return wt;
}


int main() {
  int num;
  std::cin >> num;

  std::cout << "Creating wrapper of 4 dynamic chars:\n\n";
  auto w = wrapper(4);

  std::cout << "\nCopying another wrapper from wrapper above:\n\n";
  wrapper w_copy(w);

  std::cout << "\nCreating and copying wrapper of "<<num<<" chars:\n\n";
  auto w_temp(factory(num));
  std::cout << "\nend program" << std::endl;
  return 0;
}

