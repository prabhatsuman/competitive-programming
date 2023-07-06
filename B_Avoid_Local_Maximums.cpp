#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] > v[i + 1] && v[i] > v[i - 1])
        {
            if (i < n - 2)
            {
                v[i + 1] = max(v[i], v[i + 2]);
                res++;
            }
            else
            {
                v[i + 1] = v[i];
                res++;
            }
        }
    }
    cout << res << '\n';
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << '\n';
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
