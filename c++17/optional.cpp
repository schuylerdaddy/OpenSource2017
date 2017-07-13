#include<iostream>
#include<optional>

std::optional<std::string> create(bool b) {
  if (b) {
    return "Godzilla";
  } else {
    return {};
  }
}

int main(){
  auto with_true = create(false).value_or("empty"); // == "empty"
  create(true).value(); // == "Godzilla"
  // optional-returning factory functions are usable as conditions of while and if
  if (auto str = create(true)) {
    std::cout<<str.value()<<std::endl;
  }

  std::cout<<create(false).value_or("empty- not {}")<<std::endl;
}
