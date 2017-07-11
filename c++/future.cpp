#include <future>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

mutex m;

bool f(const string & s) {
    for (int i=0; i < 10; ++i) {
        lock_guard<mutex> lck(m);   // RAII for mutexes
        cout << s << endl;
    }
    return true;
}

int main() {
    std::cout<<"task based futures:\n";
    auto future1 = std::async(f,"Dessert Topping");
    std::future<bool> future2 = std::async(f,"Floor Wax");
    auto res1 = future1.get();
    auto res2 = future2.get();

    std::cout<<"including launch policy:\n";
    future1 = std::async(std::launch::async, f,"Dessert Topping");
    future2 = std::async(std::launch::async,f,"Floor Wax");
    res1 = future1.get();
    res2 = future2.get();
}
