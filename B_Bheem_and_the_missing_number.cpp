#include<bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
        lli a,b;
        cin>>a>>b;
        lli sum=(a*(a+1))/2;
        
        cout<<sum-b<<'\n';
    }
    return 0;
}
