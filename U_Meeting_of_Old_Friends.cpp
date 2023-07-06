#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    ll m1=max(l1,l2);
    ll m2=min(r1,r2);
    if(m1>m2)cout<<0;
    else
    {
        if(k>=m1 && k<=m2)
        {
            cout<<m2-m1;
        }
        else
        {
            cout<<m2-m1+1;
        }
    }
    return 0;
}
