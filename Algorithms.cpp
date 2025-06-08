#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second < p2.second)   return true;    //its already in its correct position
    else    return false;
}

int main()
{
    int arr[4] = {4, 3, 7, 1};

    //1.sort(starting pointer, ending pointer+1)  -> in case of array
    //sort(starting iterator, ending iterator)  -> in case of iterator
    sort(arr, arr+4);

    //sort(starting, ending, greater<int>) -> in case of descending sorting
    //greater<int> is a comparator

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    vector<pair<int, int>> vec = {{3, 2}, {1, 5}, {2,9}};

    //this by default sort on basis of pair first value
    sort(vec.begin(), vec.end());

    for(auto p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }

    //now to sort on basis of second value we will use custom comparator
    sort(vec.begin(), vec.end(), comparator);

    for(auto p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }

    //2.reverse -> to reverse vector, array etc
    //reverse(starting iterator, ending iterator);
    //reverse(any pos, any pos)

    reverse(arr, arr+4);

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    reverse(arr, arr+4);
    //3.next_permutation(v.begin(), v.end())
    string s ="abc";
    next_permutation(s.begin(), s.end());
    cout << endl << s;

    //4.swap
    int a=4;
    int b=3;
    swap(a, b); 
    cout << endl << a << " " << b;

    ///5.min
    cout << endl << min(3, 5);

    //6.max
    cout << endl << max(4,66);

    //7.max_element & min_element for vectors, array    -> it returns the iterator
    cout<< endl << *max_element(arr, arr+4);

    //8.binary_search(v.begin(), v.end(), target)
    cout << endl << binary_search(arr, arr+4, 4);   //the array, vector should be sorted

    //9.__builtin_popcount()    -> used to count no of 1 in the parameter binary form
    //__builtin_popcoutnl()
    //__builtin_popcoutnll()

    return 0;
}