#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    if (m['0'] == m['1'])
    {
        cout << m['0'] * 2 << nline;
    }
    else
    {
        int res = min(m['0'], m['1']);
        cout << (res * 2) + 1 << nline;
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
