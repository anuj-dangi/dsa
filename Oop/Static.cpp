#include <iostream>
#include <vector>
using namespace std;

//for static varaibles there  scope is of class scope
class Class
{
public: 
    static int x;
};

class Static
{
public: 
    Static()
    {
        cout << "constructor" << endl;
    }

    ~Static()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    if(true)
    {
        //if use static object the object will presist until lifetime of the program
        static Static s;
    }
    cout << "end of main fxn" << endl;
    return 0;
}