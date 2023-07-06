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
    int count = 0, count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            count++;
        }
        else
        {
            count1++;
        }
    }
    cout << max(count1, count) << '\n';
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
