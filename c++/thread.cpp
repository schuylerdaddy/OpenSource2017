#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

mutex m;

void f(const string & s) {
    for (int i=0; i < 10; ++i) {
        lock_guard<mutex> lck(m);   // RAII for mutexes
        cout << s << endl;
    }
}

int main() {
    thread t1{f,"Dessert Topping"};
    thread t2{f,"Floor Wax"};
    t1.join();
    t2.join();
}
