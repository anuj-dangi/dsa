#include<iostream>
#include <string.h>
using namespace std;

void input()
{
    char str[100];  //can also be string str;

    cout << "Enter String : ";
    cin >> str; //this will ignore strings after space

    cout << str << endl;
    cin.sync();      //will remove any strings in buffer
    //to get space we have to use a special function
    char str1[50];
    cout << "Enter another string : ";
    //cin.getline(string, length, delimiter(optionla));
    cin.getline(str1, 50);

    cout << str1 << endl;
}

void strings()
{
    string str = "dsa"; //strings are dynamic in nature -> they resize at runtime   
    string str2 = " in c++";

    cout << str+str2 << endl;   //concatenation

    cout << (str == str2) << endl;

    string str3;
    cout << "input : ";
    getline(cin, str3);
    cout << str3 << endl;

    for(char ele : str3)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    //Strins -> "anything"
    //Charcter array -> Cstrings
    //we can use cstring to store a string or vice-versa
    //to do so the cstrings should have last character as '\0'->null character
    char str[5] = {'a', 'b', 'c', 'd', '\0'};

    cout << str << endl;
    cout << strlen(str) << endl;

    char str1[] = "hello";
    cout << str1[3] << endl;

    //input();
    strings();
    return 0;
}