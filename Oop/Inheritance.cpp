#include <iostream>
using namespace std;

//Inheritance
class Person
{
    public:
        string name;
        int age;
    
    Person(string name, int age)
    {
        cout << "Parent constructor" << endl;
        this->name = name;
        this->age = age;
    }

    ~Person()
    {
        cout << "Parent destructor" << endl;
    }
};

class Student : public Person
{
    public:
        int rollno;

    Student(string name, int age, int rollno) : Person(name, age)
    {
        cout << "Child constructor" << endl;
        this->rollno = rollno;
    }

    ~Student()
    {
        cout << "Child destructor" << endl;
    }

    void getInfo()
    { 
        cout << "Name : " << name << " Age : " << age << " RollNo : " << rollno << endl;
    }
};
//Multiple inheritance is allowed in c++

class Animal
{
public:
    string type;

    Animal(string type)
    {
        this->type = type;
    }

    void print()
    {
        cout << "this is animal class print method" << endl;
    }
};

class MultipleInheritance : public Person, public Animal
{
public: 
    MultipleInheritance(string name, int age, string type) : Person(name, age), Animal(type)
    {
        //do nothing
    }

    void print()
    {
        Animal:: print();
        cout << "this is Multipleinheritance class print method" << endl;
    }
};

int main()
{
    Student s("anuj", 22, 16);

    s.getInfo();

    MultipleInheritance m("anuj", 22, "mamal");

    m.print();

    return 0;
}

