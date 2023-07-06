#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;

    string s;
    ll res = 0;
    int flag = 0;
    while (1)
    {
        if (res + 2 > n)
        {
            flag = 1;
            break;
        }

        res += 2;

        s += '2';
        if (res + 1 > n)
            break;
        res++;

        s += '1';
        if (res == n)
        {
            break;
        }
    }
    if (flag == 1)
    {

        string res = "1";
        cout << res + s << '\n';
    }
    else
    {
        cout << s << '\n';
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
