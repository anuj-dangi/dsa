#include <iostream>
#include <vector>
using namespace std;
//Abstraction
//Hiding all unnecessary details & showing only the important parts
//by using access modifiers and using abstract classes
//abstract class
class Shape
{
public:
    virtual void draw() = 0;    //pure virtual function
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "drawing a circle" << endl;
    }
};

int main()
{
    Circle c;
    c.draw();
    return 0;
}