#include <iostream>
#include <vector> 
#include <map> 
#include <set> 
#include <tuple> 
#include <string>
#include <algorithm>
#include <iterator>  

auto parse_args(int argc, char** argv) { 
  std::vector<std::string> args; 	
  std::set<std::string> options; 
  std::map<std::string, std::string> sub_options;
  
  //separate and populate args, - options, and -- suboptions
  int ctr = 1; 	
  while (ctr < argc) { 
    std::string arg(argv[ctr]);
    if (arg[0] == '-') {
      if (arg.size() == 1 || arg[1] != '-')
        options.insert(arg.substr(1));
      else if (++ctr < argc)
        sub_options[arg.substr(2)] = std::string(argv[ctr]);
      
    }
    else {
       args.push_back(arg);
    }
     ++ctr;
  }
  return std::make_tuple(args, options, sub_options); 
}

template<typename container>
void dump_container(container c){
  for(const auto& e : c)
    std::cout<<e<<'\n';
}

int main(int argc, char** argv){
  auto [args, options, sub_options] = parse_args(argc,argv);
  std::cout<<"args entered:\n";
  dump_container(args);
  std::cout<<"options etnered:\n";
  dump_container(options);
  std::cout<<"suboptions and values:\n";
  for(const auto& p : sub_options)
    std::cout<<p.first<<" -> "<<p.second<<"\n";
}
