#include<iostream>
#include<memory>

struct dummy{
  int id;
  dummy(){std::cout<<"creating dummy..\n";}
  ~dummy(){std::cout<<"destroying dummy..\n";}
};

int main(){
  std::cout<<"the old way:\n";
  dummy* d1 = new dummy();
  delete d1;

  std::cout<<"the new way:\n";
  std::unique_ptr<dummy> d2(new dummy);

  std::cout<<"Even better:\n";
  auto d3 {std::make_unique<dummy>()};
}
