#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{

    ll X, M;
    cin >> X >> M;
    ll min = ceil(log2(X)) + 1;
    ll temp = 0;
    ll res = 0;

    if (min > M)
    {
        cout << "0" << '\n';
    }
    else
    {
        temp = M - min;
        res = temp  + 1;
        cout << res << '\n';
    }
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
