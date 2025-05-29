#include<iostream>
#include <vector> //Header files for vector
//Vector is just like array but have dynamic in nature means we can change its size.
//Vector comes under stl(standard template library) just like collection framework in java// Generics
//Error -> segmentation fault (trying to access a part of memory which does not exist).
int main()
{
    std::vector<int> vec;
    //Vector functions : 
    /*
        1.size()
        2.push_back() -> insert at end of vector
        3.pop_back()    -> delete from end of vector (it does not return any value)
        4.front()
        5.back()
        6.at()  -> accessing value at a particular index.
    */

    //for each loop
    vec.push_back(21);
    //std::cout << vec.pop_back(); -> Error
    for(int ele : vec)
    {
        std::cout << ele << " ";
    }


    std:: cout << vec.size();
    return 0;
}