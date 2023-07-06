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
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "NO" <<'\n';
    }
    else
    {
        cout << "YES" <<'\n';
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
