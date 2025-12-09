#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //removing the synchronization with cin,cout with c fun like printf, scanf  removing extra overhead
    ios::sync_with_stdio(false);
    //this unties automatically flushing of the cin with cout
    cin.tie(nullptr);
    //make the program faster


    return 0;
}