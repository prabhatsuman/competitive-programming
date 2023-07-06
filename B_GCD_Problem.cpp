#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    if(n%2==0)cout<<(n-2)/2<< " "<< ((n-2)/2+1)<< " "<<"1"<<'\n';
    else 
    {
        if(((n-1)/2)%2==0)
        {
            cout<<((n-1)/2)-1<< " "<< ((n-1)/2)+1<< " "<<"1"<<'\n';
        }
        else
        {
             cout<<((n-1)/2)-2<< " "<< ((n-1)/2)+2<< " "<<"1"<<'\n';
        }
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
