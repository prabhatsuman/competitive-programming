#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n1 = s.length();
    string rev = s;
    reverse(rev.begin(), rev.end());

    int ans = 0;
    
    for (int i = n1 - 1, j = n1 - 1; i >= 0;)
    {
        while (i >= 0 && s[j] != rev[i])
        {
            ans++;
            i--;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    cout << ans << '\n';
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
