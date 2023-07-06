#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int> cubes;
void precompute()
{
    
    for(ll i=1; i<=10000; i++)
    {
        cubes[i*i*i]++;
    }
}
void solve()
{
    int flag=0;
    ll x;
    cin>>x;
    for(auto &p : cubes)
    {
        if(x>p.first)
        {
            ll temp=x-p.first;
            if(cubes.find(temp)==cubes.end())
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }

        }
    }
    if(flag==1)
    {
        cout<<"YES"<<'\n';
    }
    else
    {
        cout<<"NO"<<'\n';
    }

       
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
