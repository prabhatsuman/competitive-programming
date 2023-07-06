#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll l, r, k;
    cin >> l >> r >> k;
    if (l - r == 0 && r != 1)
    {
        cout << "YES" << '\n';
        return;
    }
    if (l - r == 0 && r == 1)
    {
        cout << "NO" << '\n';
        return;
    }
    ll n = (r - l) / 2;
    if (l % 2 == 1 || r % 2 == 1)
        n++;

    if (n > k)

        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
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
