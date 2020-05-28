#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
    string s = "aabbffddeaee";
    // set<int> st;
    map<char, int> m;
    for (auto i : s)
        m[i]++;
    // for(auto i: m){
    //     if(st.insert(i))
    // }
    return 0;
}