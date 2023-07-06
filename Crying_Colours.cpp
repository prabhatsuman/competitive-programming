#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[3][3];
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
           cin>>arr[i][0];
           cin>>arr[i][1];
           cin>>arr[i][2];
        }
        ll count=0;
        if(arr[0][0]==n && arr[1][1]==n)
        {
            cout<<count<<'\n';
        }
        else
        {
            ll a=arr[1][0]+arr[2][0]+arr[2][1];
            ll b=arr[0][1]+arr[0][2]+arr[1][2];
            count=max(a,b);
            cout<<count<<'\n';
        }
    }
    return 0;
}
