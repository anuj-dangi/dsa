//This file contain standard template library of cpp
#include<iostream>
#include<vector>
using namespace std;

//Uses array as its implementation.
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

}

int main()
{
    //vectorStd();
    iteratorStd();
    return 0;
}