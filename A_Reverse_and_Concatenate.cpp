#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string temp = s;
    reverse(s.begin(), s.end());
    if (s==temp)
    {
        cout << 1 << endl;
    }
    else
    {
        if (k > 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
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
