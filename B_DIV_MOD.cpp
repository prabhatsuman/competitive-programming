#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll l, r, a;
    cin >> l >> r >> a;
    if (a > r)
    {
        cout << r << '\n';
        return;
    }
    if (r % a == 0)
    {
        if (r - 1 < l)
        {
            ll ans = r / a + r % a;
            cout << ans;
        }
        else
        {
            ll ans1 = (r - 1) / a + (r - 1) % a;
            ll ans2 = r / a + r % a;
            cout << max(ans1, ans2);
        }
    }
    else
    {
        ll rem = r % a;

        ll temp = r - rem - 1;
        if (temp < l)
        {
            ll ans = r / a + r % a;
            cout << ans;
        }
        else
        {
            ll ans1 = r / a + r % a;
            ll ans2 = temp / a + temp % a;
            cout << max(ans1, ans2);
        }
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
