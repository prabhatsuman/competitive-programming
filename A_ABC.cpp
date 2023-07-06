#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << "YES" << '\n';
        return;
    }
    if (n == 2)
    {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < 2; i++)
        {
            if (s[i] == '1')
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        if (c1 == 1 && c2 == 1)
        {
            cout << "YES" << '\n';
            return;
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    if (n > 2)
    {
        cout << "NO" << '\n';
        return;
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
