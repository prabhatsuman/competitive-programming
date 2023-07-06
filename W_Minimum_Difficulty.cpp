#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int gap=0,res=INT_MAX;
    for(int i=1; i<n; i++)
    {
        gap=max(gap,v[i]-v[i-1]);
    }
    for( int i=1;i<n-1; i++)
    {
        res=min(res,max(gap,v[i+1]-v[i-1]));
    }
    cout<<res;

    

    return 0;
}
