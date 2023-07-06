#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        else
        {
            count++;
        }
    }
    cout << count << '\n';
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
