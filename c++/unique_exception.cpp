#include<iostream>
#include<memory>
#include<exception>

struct dummy{
  int id;
  dummy(){std::cout<<"creating dummy..\n";}
  ~dummy(){std::cout<<"destroying dummy..\n";}
};

void something_complex(dummy& d){
  throw std::runtime_error("unexpected exception thrown!");
}

void raw_create(){
  std::cout<<"running raw create:\n";
  auto dum = new dummy;
  something_complex(*dum);
  delete dum;
}

void smart_create(){
  std::cout<<"running smart create:\n";
  auto dum {std::make_unique<dummy>()};
  something_complex(*dum);
}

int main(){
  try{
    raw_create();
  }
  catch(std::runtime_error x){
    std::cout<<x.what()<<std::endl;
  }
  try{
    smart_create();
  }
  catch(std::runtime_error x){
    std::cout<<x.what()<<std::endl;
  }  
}
