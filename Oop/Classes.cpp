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

//shallow copy  -> comes issue when the variables are assined memory using new operator
//as new operator assign memory from normal memory that is stack to in heap memory.
//the memory allocated through new operator is dynamic memory allocation i.e. memory is allocated on runtime
class Shallow
{
    public:
        int* num;

        Shallow(int n)
        {
            num = new int;
            *num = n;
        }

        Shallow(Shallow &s)
        {
            //shallow copy
            this->num = s.num;

            //deep copy
            num = new int;
            *this->num = *s.num;
        }

        void print()
        {
            cout << *num << endl;
        }

        //destructor -> deletes memory occupied by obj
        //it is alreay defined but for new operator memory allocation we have to manally close the memory
        ~Shallow()
        {
            delete num;
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