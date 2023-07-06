#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
     int x,y;
     cin>>x>>y;
     if(x%2==0 && y%2==0)
     {
         cout<<"Janmansh"<<'\n';
     } 
     else if(x%2==1 && y%2==1) 
     {
          cout<<"Janmansh"<<'\n';
     }
     else
     {
         cout<<"Jay"<<'\n';
     }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
