#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool killMosnter(ll x, ll y)
{
    if (x <= y)
        return true;
    else
        return false;
}
void solve()
{
    ll hc, dc, hm, dm;
    cin >> hc >> dc >> hm >> dm;
    ll k, w, a;
    cin >> k >> w >> a;
    ll x, y;
    ll t1 = dc, t2 = hc;
    for (int i = 0; i <= k; i++)
    {

        dc = t1 + (k - i) * w;
        hc = t2 + i * a;

        if (hm % dc == 0)
            x = hm / dc;
        else
            x = (hm / dc) + 1;
        if (hc % dm == 0)
            y = hc / dm;
        else
            y = (hc / dm) + 1;

        if (killMosnter(x, y))
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
