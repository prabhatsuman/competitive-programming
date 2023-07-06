#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 1;
    int j = n - 1;
    ll sum1 = v[0];
    ll sum2 = 0;
    int flag = 0;
    while (i < j)
    {
        sum1 += v[i];
        i++;
        sum2 += v[j];
        j--;
        if (sum2 > sum1)
        {
            flag = 1;
            break;
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
