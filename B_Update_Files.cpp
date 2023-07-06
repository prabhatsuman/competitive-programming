#include <bits/stdc++.h>
#define ll long long
#define nline '\n'
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 0 << nline;
        return;
    }
    ll res = 0;
    ll temp = 1, w = 1;

    while (w <= k)
    {
        temp += temp;
        w += w;
        res++;
        if (temp >= n)
        {

            cout << res << nline;
            return;
        }
    }

    ll rem = n - temp;
    res += (rem / k);
    if (rem % k != 0)
        res++;

    cout << res << nline;
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
