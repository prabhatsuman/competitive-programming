#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll x, n;
    cin >> x >> n;
    if (x % 2 == 0)
    {
        ll rem = n / 4;

        if (n % 4 == 0)
        {
            cout << x;
        }
        else if (n % 4 == 1)
        {
            cout << x - (4 * rem + 1);
        }
        else if (n % 4 == 2)
        {
            cout << x + 1;
        }
        else if (n % 4 == 3)
        {
            cout << (x + 1) + (4 * rem + 3);
        }
    }
    else
    {
        ll rem = n / 4;
        if (n % 4 == 0)
        {
            cout << x;
        }
        else if (n % 4 == 1)
        {
            cout << x + (4 * rem + 1);
        }
        else if (n % 4 == 2)
        {
            cout << x - 1;
        }
        else if (n % 4 == 3)
        {
            cout << (x - 1) - (4 * rem + 3);
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
