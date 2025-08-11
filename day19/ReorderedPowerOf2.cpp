#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//leetcode - 869
class Solution {
public:
    // Helper function: returns a sorted string of the digits in the number
    string getSortedDigits(int number) {
        string digits = to_string(number); // Convert number to string
        sort(digits.begin(), digits.end()); // Sort digits in ascending order
        return digits;
    }

    bool reorderedPowerOf2(int n) {
        // Step 1: Get the sorted digits of the given number
        string targetDigits = getSortedDigits(n);

        // Step 2: Check all powers of 2 up to 2^30
        for (int i = 0; i < 31; i++) {
            int powerOfTwo = 1 << i; // Same as pow(2, i)
            string powerDigits = getSortedDigits(powerOfTwo);

            // Step 3: Compare sorted digits
            if (powerDigits == targetDigits) {
                return true; // Found a match
            }
        }

        // Step 4: No match found
        return false;
    }
};
