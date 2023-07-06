#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int x;
    cin >> x;
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int req = x - 1;
    int res = req * v[0] + v[1];
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
