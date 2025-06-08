//This file contain standard template library of cpp
#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

//Uses dynamic array as its internal implementation.
//Each time vector size get full it double its capacity.
void vectorStd()
{
    vector<int> vec(3, 0);  //Initializes a 3 size vector with all values as zero.
    vector<int> vec2(vec);  //Copy vec into vec2.

    //The function down bellow are all take time complexity of O(1)
    vec2.push_back(4);
    vec2.pop_back();
    vec2.at(1); //same as vec[1]
    vec2.push_back(12);


    cout << "Size : " << vec2.size() << " Capacity : " << vec2.capacity();
    cout << "vector front : " << vec2.front() << " Vector back : " << vec2.back();

    //The function down bellow are heavy function like erase and insert there time complexity is large so try to avoid using them

    //Erase changes the size but does not changes the capacity
    vec2.erase(vec2.begin()+2, vec2.end()-1);   //It takes an iterator as parameter and deletes elements in a range. erase(start, end(optional)).
    cout << '\n';
    for(int ele : vec2)
    {
        cout << ele << " ";
    }
    
    //vec.begin() -> like an pointer(but its a iterator) that points at position 0 of vector.
    //vec.end() -> iterator that points at n position of vector(not n-1).
    vec2.insert(vec2.begin()+1, 22);        //insert(pos, value)
    cout << '\n';
    for(int ele : vec2)
    {
        cout << ele << " ";
    }

    cout << *(vec.begin()) << " " << *(vec.end());//vec.end will give garbage value

    vec.clear();    //will clear our vector //capacity will remain same.

    vec.empty();    //will return 1 if empty or 0 if not
    cout<< "\n" << vec.empty();
}

void iteratorStd()
{
    vector<int> vec = {1, 2, 3, 4};

    vector<int>::iterator it;   //normal iterator

    for(it=vec.begin(); it!=vec.end();it++)
    {
        cout << *(it) << " ";
    }
    cout << "\n";
    //reverse iterator
    for(vector<int>::reverse_iterator it=vec.rbegin();it!=vec.rend();it++)
    {
        cout << *(it) << " ";
    }
    cout << "\n";
    //Instead of writing this large syntax we can use 'auto' and c++ will automatically see what's is that
    for(auto it=vec.begin(); it!=vec.end();it++)
    {
        cout << *(it) << " ";
    }
}

//Internally implemented using double liked list
void listStd()
{
    list<int> li = {1, 2, 3};
    list<int> l(li);

    for(auto it=l.begin();it!=l.end();it++)
    {
        cout << *(it)<<" ";
    }

    // As list is implemented as double link list both front and back operation can be done
    // push_back & push_front
    // emplace_back & emplace_front
    // pop_back & pop_front
    //size, erase, clear, begin, end, rbegin, rend, insert, front, back

    l.push_back(5);
    l.push_front(0);
    cout << "\n";
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout << *(it)<<" ";
    }

}

//Double ended queue
//Same operations as list
//Internally implemented as dynamic array
//any element can be accessed using index, this is not possible in list
void dequeStd()
{
    deque<int> d = {1, 2, 3};

    // As deque is implemented as double ended queue there are queue at both side front and back operation can be done
    // push_back & push_front
    // emplace_back & emplace_front
    // pop_back & pop_front
    //size, erase, clear, begin, end, rbegin, rend, insert, front, back

    cout << d[2];
}

int main()
{
    //vector, list, deque -> this all are called sequential containters(as it stores data in a sequentail manners)
    //vectorStd();
    //iteratorStd();
    //listStd();
    //dequeStd();
    return 0;
}