#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

void func(mutex &mx)
{
    {
        lock_guard<mutex> lock(mx);
        cout << "Inside Thread :: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(4));
    }
}

bool run = true;
void conFunc(mutex &mx, condition_variable &cvar)
{
    unique_lock<mutex> lock(mx);
    cvar.wait(lock);
    // while (run)
    // {
    // }
    cout << "Inside conFunc Thread :: " << this_thread::get_id() << endl;
}
int main()
{
    mutex mxt;
    // thread t1(func, ref(mxt));
    // this_thread::sleep_for(chrono::seconds(1));
    // unique_lock<mutex> lock(mxt);
    // cout << "Inside Main Thread :: " << this_thread::get_id() << endl;
    // lock.unlock();
    // t1.join();
    condition_variable cvar;
    thread t2(conFunc, ref(mxt), ref(cvar));
    cout << "Inside Main Thread :: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(10));
    {
        lock_guard<mutex> lock(mxt);
        cvar.notify_all();
    }
    run = false;
    t2.join();

    return 0;
}