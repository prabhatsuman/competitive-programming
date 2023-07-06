#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int odd = 0, even = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int temp = s[i] - '0';
        if (temp % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (even > 1 && odd == 0)
    {
        cout << "YES" << nline;
    }
    else if (odd > 1 && even == 0)
    {
        cout << "YES" << nline;
    }
    else
    {
        int temp = s[s.length() - 1] - '0';
        if (temp % 2 == 0)
        {
            if (even > 1)
            {
                cout << "YES" << nline;
            }
            else
            {
                cout << "NO" << nline;
            }
        }
        else
        {
            if (odd > 1)
            {
                cout << "YES" << nline;
            }
            else
            {
                cout << "NO" << nline;
            }
        }
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
