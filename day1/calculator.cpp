#include<iostream>
using namespace std;

void mainMenu()
{
    cout << "1. Sum\n2. Sub\n3. Multiplication\n4. Division\n5. Modulo\n6. Exit\nEnter your choice : ";
}

int main()
{
    int choice = 0, a, b;

    while(choice != 6)
    {
        mainMenu();
        cin >> choice;

        if(choice >= 1 && choice <= 5)
        {
            cout << "a : ";
            cin >> a;
            cout << "b : ";
            cin >> b;
        }

        switch(choice)
        {
            case 1: cout << a+b;
                    break;
            case 2: cout << a-b;
                    break;
            case 3: cout << a*b;
                    break;
            case 4: cout << a/b;
                    break;
            case 5: cout << a%b;
                    break;
            case 6: cout << "Exiting the program....";
                    break;
            default: cout << "Error, try again";
                    break;
        }
        cout << "\n\n";
    }
}