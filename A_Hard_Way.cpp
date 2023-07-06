#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (y1 == y2 && y3 < y1)
    {
        cout << abs(x2 - x1) << '\n';
    }
    else if (y1 == y3 && y2 < y1)
    {
        cout << abs(x3 - x1) << '\n';
    }
    else if (y2 == y3 && y1 < y3)
    {
        cout << abs(x3 - x2) << '\n';
    }
    else
    {
        cout << 0 << '\n';
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
