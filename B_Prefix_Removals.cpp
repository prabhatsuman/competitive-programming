#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (m[*it] > 1)
        {
            m[*it]--;
            s.erase(it);
            it--;

        }
        else
        {
            break;
        }
    }
    cout << s << nline;
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
