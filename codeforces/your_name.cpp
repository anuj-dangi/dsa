#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int q;
    cin >> q;
    
    while(q--)
    {
        int n;
        cin >> n;
        
        string s, t;
        cin >> s >> t;
        
        if(s.size() != n || t.size() != n)
            cout << "NO" << endl;
        else{
            
        vector<int> ps(n, 0);
        bool err = false;
        
        for(int i=0;i<n;i++)
        {
            err = false;
            for(int j=0;j<n;j++)
            {
                if(t[i] == s[j] && ps[j] == 0)
                {
                    ps[j] = 1;
                    err = true;
                    break;
                }
            }
            if(!err){
                cout << "NO" << endl;
                break;
            }
        }
        if(err)
            cout << "YES"<<endl;
    }
        
    }
    return 0;
}