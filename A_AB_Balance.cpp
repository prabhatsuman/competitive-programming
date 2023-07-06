#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    
    if (s[0] == s[n - 1])
    {
        cout << s << '\n';
    }
    else
    {
        s[n - 1] = s[0];
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
