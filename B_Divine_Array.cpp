#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, int> count(vector<int> &v)
{
    unordered_map<int, int> m;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        m[*it]++;
    }
    return m;
}
void update(vector<int> &v, unordered_map<int, int> &m)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        *it = m[*it];
    }
}
void solve()
{
    vector<vector<int>> ans;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k = 0;
    while (1)
    {
        int flag = 0;
        ans.push_back(v);
        unordered_map<int, int> m;
        m = count(v);
        update(v, m);
        for (auto &p : m)
        {
            if (p.first != p.second)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        else
        {
            k++;
        }
    }
    int q;
    cin >> q;

    while (q--)
    {
        int x, p;
        cin >> x >> p;
        if (p > k)
            cout << ans[k][x - 1] << '\n';
        else
            cout << ans[p][x - 1] << '\n';
    }
    // for(auto &v1 : ans)
    // {
    //     for(auto &v2 : v1)
    //     {
    //         cout<<v2<<" ";
    //     }
    //     cout<<endl;
    // }
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
