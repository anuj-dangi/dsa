#include <iostream>
#include <vector>
using namespace std;

//Polymorphism is the ability of objecsts to take on different forms or behave in different ways depending on the context in which they are used.
//Practical example -> constructor overloading  -> this is a compile time polymorphism 
class Polymorphism
{
public:
    //constructor overloading
    Polymorphism()
    {
        cout << "Non-parametrized constructor" << endl;
    }

    Polymorphism(int a)
    {
        cout << "Parametrized constructor" << endl;
    }
    //function overloading
    //other example of complile time polymorphism is operator overloading
    void print(int a)
    {
        cout << "Number : " << a << endl;
    }

    void print(char a)
    {
        cout << "Char : " << a << endl;
    }
    
    //The child class have to override virtual function 
    //virtual is also a runtime polymorphism example
    virtual void method()
    {
        cout << "Parent virtual method" << endl;
    }
};

class Child : public Polymorphism
{
    
};

//function overriding -> runtime polymorphism
int main()
{
    Polymorphism p;
    Polymorphism p2(1);

    p.print(4);
    p.print('r');

    Child c;
    return 0;
}