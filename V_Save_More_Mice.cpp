#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    ll moves = 0;
    vector<ll> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    for (int i = 0; i < k; i++)
    {
        moves += (n - v[i]);
        if (moves < n)
        {
           res++;
        }
       
    }
    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
