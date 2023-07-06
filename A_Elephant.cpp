#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll moves;
    if(n%5==0)
    {
        moves=(n/5);
    }
    else
    {
        moves=(n/5)+1;
    }
    cout<<moves<<'\n';
    
    return 0;
}
