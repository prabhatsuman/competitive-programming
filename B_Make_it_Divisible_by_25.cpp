#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int res1 = 0, res2 = 0;
    int t1 = -1, t2 = -1;
    // last 5
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != '5')
        {
            res1++;
        }
        else
        {
            t1 = i;
            break;
        }
    }
    for (int i = t1 - 1; i >= 0; i--)
    {
        if (s[i] != '2' && s[i] != '7')
        {
            res1++;
        }
        else if (s[i] == '2' || s[i] == '7')
        {
            break;
        }
    }
    // last 0
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            res2++;
        }
        else
        {
            t2 = i;
            break;
        }
    }
    for (int i = t2 - 1; i >= 0; i--)
    {
        if (s[i] != '0' && s[i] != '5')
        {
            res2++;
        }
        else if (s[i] == '0' || s[i] == '5')
        {
            break;
        }
    }
    cout << min(res1, res2) << '\n';
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
