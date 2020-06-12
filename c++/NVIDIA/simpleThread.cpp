#include <iostream>
#include <thread>
#include <vector>

using namespace std;

template <typename Type>
void fun(Type x)
{
    cout << " Type of the this Thread :: " << typeid(Type).name() << endl;
}

int main()
{
    int local = 100;
    thread t1{[=]() {
        cout << "I am inside the thread :: " << this_thread::get_id() << endl;
        cout << "value inside Thread is = " << local << endl;
    }};
    t1.join();

    cout << "I am inside Main thread :: " << this_thread::get_id() << endl;
    cout << "value in Main Thread is = " << local << endl;

    thread t2{fun<int>, 10};
    this_thread::sleep_for(chrono::milliseconds(1000));
    vector<int> v = {1, 2, 3};
    thread t3{fun<vector<int>>, v};

    t2.join();
    t3.join();

    return 0;
}