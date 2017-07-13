#include<iostream>
#include<optional>

int main(){
  std::optional<std::string> create(bool b) {
    if (b) {
      return "Godzilla";
    } else {
      return {};
    }
  }

  create(false).value_or("empty"); // == "empty"
  create(true).value(); // == "Godzilla"
  // optional-returning factory functions are usable as conditions of while and if
  if (auto str = create(true)) {
    // ...
  }
} 
