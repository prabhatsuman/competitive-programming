#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[(a[i] % 10)]++;
    }
    if (m[1] >= 3)
    {
        cout << "YES";
        return;
    }
    for (ll i = 0; i < 10; i++)
        if (m[i] >= 2)
        {
            if (m[3 - 2 * i] >= 1 || m[13 - 2 * i] >= 1 || m[23 - 2 * i] >= 1)
            {
                cout << "YES";
                return;
            }
        }
    // three cases
    // either check for 2 values or single 3 values or 1*3
    vector<ll> v;
    for (ll i = 0; i < 10; i++)
    {
        if (m[i] >= 1)
            v.push_back(i);
    }

    for (ll i = 0; i < v.size(); i++)
        for (ll j = i+1; j < v.size(); j++)
            for (ll k = j+1; k < v.size(); k++)
            {

                if (v[i] + v[j] + v[k] == 3 || v[i] + v[j] + v[k] == 13 || v[i] + v[j] + v[k] == 23)
                {
                    cout << "YES";
                    return;
                }
            }

    cout << "NO";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}