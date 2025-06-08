//This file contain standard template library of cpp
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
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

//Pair can be used as we use primitive data type like int, float, double
void pairUtility()
{
    pair<string, int> p = {"anuj", 16};

    cout << p.first << " "<< p.second;

    pair<string, pair<string, int>> id = {"anuj", {"uoh", 16}};

    cout << endl << id.first << " " << id.second.first << " " << id.second.second;

    //vector example
    vector<pair<int, int>> vec = {{1, 2},{3, 4}};

    cout << vec[1].first << endl;

    for(pair<int,int> pa : vec)
    {
        cout << pa.first << " " << pa.second << endl;
    }

    vec.push_back({5,6});
    vec.emplace_back(7, 8);         //In-place object create the emplace_back will automatically make pair of 7, 8

    for(auto pa : vec)
    {
        cout << pa.first << " " << pa.second << endl;
    }
}

//LIFO -> last in first out
void stackStl()
{
    stack<int> s;
    //Stack operations -> push, emplace, top, pop, size, empty, swap
    s.push(1);
    s.push(2);
    s.push(3);

    stack<int> s2;
    s2.swap(s);
    cout << s.size() << " " << s2.size();
    //cout << s2.pop() -> error , because pop() does not return anything
    cout << s2.top() << endl;
    s2.pop();

    while(!s2.empty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }
    //time complexity top(), pop(), push() -> O(1)
}

//FIFO -> first in first out
void queueStl()
{
    //Queue operations -> push, emplace, front, pop, size, empty, swap

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    queue<int> q2;
    q.swap(q2);

    while(!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }

    //time complexity top(), pop(), push() -> O(1)
}

//Uses Max(max element at top) or Min(min element at top) Heap as its internal implementation -> Complete binary tree
void priorityQueueStl()
{
    //priority_queue operations -> push, emplace, top, pop, size, empty, swap
    priority_queue<int> pq;
    //Just assume a queue in which the priority element will get poped first.

    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(10);

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    //The above implementaion gives max heap implemenatation or we can say at top max priority element is there
    //For reverse priority queue -> min heap (smallest element at top)
    priority_queue<int, vector<int>, greater<int>> rpq;
    //here in reverse priority queue the greater<int> is nothing but functor(a function) which is like a comparator (which tells how to sort)

    rpq.push(4);
    rpq.push(1);
    rpq.push(5);
    rpq.push(10);
    cout <<endl;
    while(!rpq.empty())
    {
        cout << rpq.top() << " ";
        rpq.pop();
    }

    //In priority queue time complexity for top() -> O(1), push, emplace() -> O(logn)(as internally they are tree), pop() -> O(logn)
}

int main()
{
    //vector, list, deque -> this all are called sequential containters(as it stores data in a sequentail manners)
    //vectorStd();
    //iteratorStd();
    //listStd();
    //dequeStd();

    //pair -> included in c++ utility library (does not have to be explecitly included)
    //pairUtility();

    //Non-sequential container
    //stackStl();
    //queueStl();
    priorityQueueStl();
    return 0;
}