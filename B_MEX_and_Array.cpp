#include <bits/stdc++.h>
#define ll long long
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
    //count the element in all subarray
    for (int i = 0; i < n; i++)
    {
        res += (i + 1) * (n - i);
        if (v[i] == 0)
            res += (i + 1) * (n - i);
    }

    cout << res << '\n';
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
