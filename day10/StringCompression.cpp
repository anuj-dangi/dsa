#include <iostream>
#include <vector>
using namespace std;

//Time complexity of O(n)
//leetcode problem - 443
int compress(vector<char> &chars)
{

    int index = 0;

    for (int j = 0; j < chars.size(); j++)
    {
        char charVal = chars[j];
        int count = 0;
        while (j < chars.size() && chars[j] == charVal)
        {
            count++;
            j++;
        }

        chars[index++] = charVal;
        if (count > 1)
        {
            string digits = to_string(count);
            int k = 0;
            while (k < digits.size())
            {
                chars[index++] = digits[k++];
            }
        }
        j--;
    }
    return index;
}

int main()
{
    vector<char> chars = {'a','a','b','b','c','c','c'};

    cout << compress(chars) << endl;
    return 0;
}