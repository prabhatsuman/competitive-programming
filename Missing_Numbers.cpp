#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    ll a, b, c, d, x, y, prod, quo;
    bool flag = false;
    cin >> a >> b >> c >> d;
    if (((a + b) % 2) == 0)
    {
        x = (a + b) / 2;
        y = abs((a - b)) / 2;

        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == c || prod == d) && (quo == c || quo == d) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    else if (((a + c) % 2) == 0)
    {
        x = (a + c) / 2;
        y = abs((a - c)) / 2;
        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == b || prod == d) && (quo == b || quo == d) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    else if (((a + d) % 2) == 0)
    {

        x = (a + d) / 2;
        y = abs((a - d)) / 2;
        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == c || prod == b) && (quo == c || quo == b) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    else if (((b + c) % 2) == 0)
    {
        x = (b + c) / 2;
        y = abs((b - c)) / 2;
        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == a || prod == d) && (quo == a || quo == d) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    else if (((b + d) % 2) == 0)
    {
        x = (b + d) / 2;
        y = abs((b - d)) / 2;
        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == c || prod == a) && (quo == c || quo == a) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    else if (((c + d) % 2) == 0)
    {
        x = (c + d) / 2;
        y = abs((c - d)) / 2;
        prod = x * y;
        if (y != 0)
            quo = x / y;
        if ((prod == a || prod == b) && (quo == a || quo == b) && ((x >= 1 && x <= 1e4) && (y >= 1 && y <= 1e4)))
        {
            cout << x << " " << y << "\n";
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << -1 << " " << -1 << nline;
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
