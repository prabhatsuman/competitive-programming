#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    vector<int> res(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (res[i - 1] + x <= b)
        {
            res[i] = res[i - 1] + x;
        }
        else
        {
            res[i] = res[i - 1] - y;
        }
    }
    ll sum = 0;
    for (auto &e : res)
        sum += e;
    cout << sum << nline;
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
