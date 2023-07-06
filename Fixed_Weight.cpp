#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n, x;
    cin >> n >> x;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        ll rem;
        if (x % i == 0)
        {
            rem = x / i;
            if (rem >= 1 && rem <= n)
            {

                if (i == 1)
                {
                    flag = 1;
                    break;
                }
                else if (i == n)
                {
                    if (rem == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    if ((n - i) + 1 >= rem)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    if (flag == 1)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
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
