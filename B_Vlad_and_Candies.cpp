#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](int &a, int &b)
         { return a > b; });
    if (n == 1 && v[0] > 1)
    {
        cout << "NO" << nline;
        return;
    }
    if (n == 1 && v[0] == 1)
    {
        cout << "YES" << nline;
        return;
    }

    if (v[0] - v[1] > 1)
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
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
