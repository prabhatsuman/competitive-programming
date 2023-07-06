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
    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != i + 1)
        {
            flag = 1;
            start = i;
            break;
        }
    }
    if (flag == 0)
    {
        for (auto &ele : v)
        {
            cout << ele << " ";
        }
        cout << '\n';
    }
    else
    {
        for (int i = start; i < n; i++)
        {
            if (v[i] == start + 1)
            {
                end = i;
                break;
            }
        }
        reverse(v.begin() + start, v.begin() + end+1);
        for (auto &ele : v)
        {
            cout << ele << " ";
        }
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
