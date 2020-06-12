#include <iostream>
#include <future>
// #include <Future-Promise>

using namespace std;

int asyncFunc(int x)
{
    cout << "Inside the async :: " << this_thread::get_id() << endl;
    return x + 100;
}
void threadFunc(promise<int> &prom)
{
    // cout << "Inside the Thread :: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    prom.set_value(100);
}
int main()
{
    promise<int> prom;
    future<int> fp = prom.get_future();
    // cout << fp.get();
    cout << "Inside the Main :: " << this_thread::get_id() << endl;
    thread t1{threadFunc, ref(prom)};
    cout << "output from promise :: " << fp.get() << endl;
    t1.join();
    // future<int> fu = async(launch::async, asyncFunc, 200);
    // if (fu.valid())
    //     cout << fu.get() << endl;
    return 0;
}