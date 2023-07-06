#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str = "abcdefghijklmnopqrstuvwxyz";
        string res = "";
        int n;
        cin >> n;
        int temp = n / 26;
        for (int i = 1; i <= temp; i++)
        {
            res += str;
        }
        if (n % 26 == 0)
        {
            cout<<res<<'\n';
        }
        else
        {
            int rem=n%26;
            for(int j=0;j<rem;j++)
            {
                res+=str[j];
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}
