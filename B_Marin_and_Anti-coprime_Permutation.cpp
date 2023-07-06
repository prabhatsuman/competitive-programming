#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll fact(ll n)
{
    if (n == 1)
        return 1;
    return (n % 998244353 * fact(n - 1) % 998244353) % 998244353;
}
void solve()
{
    ll n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << nline;
        return;
    }
    cout << (fact(n / 2) % 998244353 * fact(n / 2) % 998244353) % 998244353 << nline;
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
