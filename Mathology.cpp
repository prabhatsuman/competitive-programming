#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    while (q--)
    {
        int r1;
        int l, r;
        cin >> l >> r;
        for (int i = l; i < r; i++)
        {
            int res = v[i + 1];
            for (int j = i + 1; j < r; j++)
            {
                if (res <= __gcd(res, v[j + 1]))
                    res = __gcd(res, v[j + 1]);
                else
                    break;
            }
            
        }
        cout << r1 << nline;
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
