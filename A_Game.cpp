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

    int res = 0;
    int temp = 2;
    for (int i = 1; i < n - 1; i++)
    {
        if (res > 0)
        {
            temp++;
        }
        if (v[i] == 0)
        {
            res = temp;
        }
    }
    cout << res << nline;
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
