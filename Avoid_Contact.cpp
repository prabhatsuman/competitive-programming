#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int X,Y;
        cin>>X>>Y;
        ll res;
        if (X==Y) res= (Y*2)-1;
        else  res = (Y*2)+(X-Y);
        
        cout<<res<<'\n';
    }
    return 0;
}
