#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(),greater<int> ());
    ll diff= v[a-1]-v[a];
    cout<<diff<<'\n';
    return 0;
}
