#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 10000000007;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < b; j++)
        {
            int x, y;
            cin >> x >> y;
            ll res = (x * v[a]) % M;
            v[y] = (v[y] + res) % M;
        }
        v[a] = 0;
    }
    // cout << v.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}
