#include<iostream>

using namespace std;

double myPow(double x, int n) 
{
        
        long binForm = n;
        if(x == 0) return 0.0;

        if(binForm < 0)
        {
            x = 1/x;
            binForm *= -1;
        }
        double ans = 1;
        while(binForm > 0)
        {
            if(binForm%2 == 1)
                ans *= x;
            
            x *= x;
            binForm /= 2;
        }

        return ans;
}

int main()
{
    //Find x^n but with O(logn)

    cout << myPow(5, -1000);
    return 0;
}