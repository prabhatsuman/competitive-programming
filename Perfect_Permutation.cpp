#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, k;

    cin >> n >> k;

    if (n - k == 1)
    {
        cout << n<< " ";
        for (int i = 2; i <= k; i++)
        {
            cout << i << " ";
        }
        cout << "1" << '\n';
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
        for (int i = k + 2; i <= n; i++)
        {
            cout << i << " ";
        }
        if (n != k)
            cout << k + 1 << '\n';
        else
            cout << '\n';
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
