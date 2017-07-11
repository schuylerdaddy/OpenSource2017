#include<iostream>
#include<memory>

struct dummy{
  int id;
  dummy(){std::cout<<"creating dummy..\n";}
  ~dummy(){std::cout<<"destroying dummy..\n";}
};

void copy(std::shared_ptr<dummy> dums,int depth){
   std::cout<<"references to dums = "<<dums.use_count()<<'\n';
   if(--depth)
     copy(dums,depth);
   std::cout<<"references to dums = "<<dums.use_count()<<'\n';  
}
int main(){
  auto dums{std::make_shared<dummy>()};
  copy(dums,3); 
}
