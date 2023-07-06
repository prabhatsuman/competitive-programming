#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> res;
    vector<int> v;
    for (int i = n; i > 0; i--)
    {
        v.push_back(i);
    }
    res.push_back(v);
    vector<int> temp = v;
    for (int i = 0; i < n - 1; i++)
    {
        swap(temp[i], temp[i + 1]);
        res.push_back(temp);
        temp = v;
    }
    for (auto &m : res)
    {
        for (auto &e : m)
        {
            cout << e << " ";
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
