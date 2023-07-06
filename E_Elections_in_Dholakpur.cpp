#include <bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    lli res=0;
    n=(n/2)+1;
    for(int i=0;i<n;i++)
    {
        res+=(arr[i]/2)+1;
    }
    cout<<res<<'\n';

    return 0;
}
