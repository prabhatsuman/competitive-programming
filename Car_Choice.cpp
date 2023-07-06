#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c / a > d / b)
    {
        cout << 1 << '\n';
    }
    else if (c / a < d / b)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<0<<'\n';
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
