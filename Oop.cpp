#include <iostream>
#include <vector>
using namespace std;

//By default in cpp access modifier(private, public, protected) is set to private
class Person
{
    public: 
        string name;
        int age;
    
        Person()
        {
            cout << "this is non-parameterized constructor" << endl;
        }
        //parameterized constructor
        Person(string name, int age)
        {   
            // this->var == (*this).var
            this->name = name;
            this->age = age;
        }

        //Copy constructor
        Person(Person &a)
        {
            *this = a;
        }

        void getInfo()
        {
            cout << "Name : " << name << endl;
        }
};

//shallow copy
class Shallow
{
    public:
        int* num;

        Shallow(int n)
        {
            num = &n;
        }

        Shallow(Shallow &s)
        {
            num = new int;
            *this->num = *s.num;
        }

        void print()
        {
            cout << *num << endl;
        }
};

int main()
{
    // Person p;
    // p.name = "anuj";
    // p.age = 22;
    // p.getInfo();

    // Person np(p);
    // np.getInfo();
    // p.name = "new name";
    // np.getInfo();
    // p.getInfo();

    //shallow copy

    Shallow a(34);
    Shallow b(a);
    b.print();
    *(a.num) = 111;
    b.print();

    return 0;
}