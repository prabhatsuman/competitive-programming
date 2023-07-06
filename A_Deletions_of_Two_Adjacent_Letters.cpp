#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    char c;
    cin >> c;
    int n = s.length();
    int flag = 0;
    // cout<<s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            if (i % 2 == 1)
                continue;

            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
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
