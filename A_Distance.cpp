#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    if((x+y)%2==0)
    {
        if(x%2==0 && y%2==0)
        {
            cout<<x/2<<" "<<y/2<<'\n';
        }
        else
        {
            cout<<x/2+1<<" "<<y/2<<'\n';
        }
    }
    else
    {
        cout<<"-1"<<" "<<"-1"<<'\n';
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
