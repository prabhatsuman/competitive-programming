#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n > k)
    {
        int temp = 0;
        if (n % k == 0)
        {
            temp = n / k;
        }
        else
        {
            temp = (n / k) + 1;
        }
        k *= temp;
        if (k % n == 0)
        {
            cout << k / n << '\n';
        }
        else
        {
            cout << (k / n) + 1 << '\n';
        }
    }
    else
    {
        if (k % n == 0)
        {
            cout << k / n << '\n';
        }
        else
        {
            cout << (k / n) + 1 << '\n';
        }
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
