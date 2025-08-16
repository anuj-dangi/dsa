#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getSum(int a, int b)
{

        while (b != 0) {
            int carry = a & b;   
            a = a ^ b;           
            b = carry << 1;      
        }
        return a;

        // bool aneg = false, bneg = false, great = false;

        // if(a < 0)
        // {
        //     a = -1*a;
        //     aneg = true;
        //     if(a > b)
        //     {
        //     great = true; 
        //     }
        // }

        // if(b < 0)
        // {
        //     b = -1*b;
        //     bneg = true;
        //     if(a < b)
        //     {
        //     great = true; 
        //     }
        // }
        // int big = log2(a) > log2(b) ? log2(a) + 1 : log2(b) + 1;

        // int out[big + 1] = {0}, aarr[big+1]= {0}, barr[big+1]= {0};

        // int count = 0, next = 0;
        // while (a > 0 && b > 0)
        // {
        //     aarr[count] = a%2;
        //     barr[count++] = b%2;
        //     a /= 2;
        //     b /= 2;
        // }

        // while (a > 0)
        // {
        //     aarr[count++] = a%2;
        //     a /= 2;
        // }

        // while (b > 0)
        // {
        //     barr[count++] = b%2;
        //     b /= 2;
        // }

        // if(aneg == true)
        // {
        //     next = 1;
        //     for(int i=0;i<big+1;i++)
        //     {
        //         aarr[i] = aarr[i] == 0 ? 1 : 0;
        //     }

        //     for(int i=0;i<big+1;i++)
        //     {
        //         if (next == 0 && aarr[i] == 0)
        //         {
        //             aarr[i] = 0;
        //             next = 0;
        //         }
        //         else if (next == 1 &&  aarr[i] == 1)
        //         {
        //             aarr[i] = 0;
        //             next = 1;
        //         }
        //         else
        //         {
        //             aarr[i] = 1;
        //             next = 0;
        //         }

        //         if(next == 0)   break;
        //     }
        // }

        // if(bneg == true)
        // {
        //     next = 1;
        //     for(int i=0;i<big+1;i++)
        //     {
        //         barr[i] = barr[i] == 0 ? 1 : 0;
        //     }

        //     for(int i=0;i<big+1;i++)
        //     {
        //         if (next == 0 && barr[i] == 0)
        //         {
        //             barr[i] = 0;
        //             next = 0;
        //         }
        //         else if (next == 1 &&  barr[i] == 1)
        //         {
        //             barr[i] = 0;
        //             next = 1;
        //         }
        //         else
        //         {
        //             barr[i] = 1;
        //             next = 0;
        //         }

        //         if(next == 0)   break;
        //     }
        // }
        // next = 0;
        // count = 0;
        // for(int i=0;i<big+1;i++)
        // {
        //     cout << "a : "<< aarr[i] << "b: " << barr[i] << endl;
        //     if (aarr[i] == 0 && barr[i] == 0 && next == 0)
        //     {
        //         out[count++] = 0;
        //         next = 0;
        //     }
        //     else if ((aarr[i] == 1 && barr[i] == 0 && next == 0) || (aarr[i] == 0 && barr[i] == 1 && next == 0) || (aarr[i] == 0 && barr[i] == 0 && next == 1))
        //     {
        //         out[count++] = 1;
        //         next = 0;
        //     }
        //     else if ((aarr[i] == 1 && barr[i] == 1 && next == 0) || (aarr[i] == 1 && barr[i] == 0 && next == 1) || (aarr[i] == 0 && barr[i]  == 1 && next == 1))
        //     {
        //         out[count++] = 0;
        //         next = 1;
        //     }
        //     else
        //     {
        //         out[count++] = 1;
        //         next = 1;
        //     }
        // }
        // for(auto ele : out)
        //     cout << ele << endl;

        // if(great == true)
        // {
        //     next = 1;
        //     for(int i=0;i<big+1;i++)
        //     {
        //         out[i] = out[i] == 0 ? 1 : 0;
        //     }

        //     for(int i=0;i<big+1;i++)
        //     {
        //         if (next == 0 && out[i] == 0)
        //         {
        //             out[i] = 0;
        //             next = 0;
        //         }
        //         else if (next == 1 &&  out[i] == 1)
        //         {
        //             out[i] = 0;
        //             next = 1;
        //         }
        //         else
        //         {
        //             out[i] = 1;
        //             next = 0;
        //         }

        //         if(next == 0)   break;
        //     }
        // }

        // int ans = 0;
        // for (int i = 0; i < count; i++)
        // {
        //     if (out[i] == 1)
        //     {
        //         ans += pow(2, i);
        //     }
        // }

        // return ans;
}

int main()
{
    cout << getSum(-11, 5) << endl;
    return 0;
}