#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);

    ll sum = 0, p = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            while (v[i] % 2 == 0)
            {
                v[i] /= 2;
                p++;
            }
        }
    }
    sort(v.begin(), v.end());
    ll temp=v.back();
    temp=temp*pow(2,p);

    for (int i = 0; i < n - 1; i++)
    {
        sum += v[i];
    }
    cout << sum+ temp  << '\n';
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
