#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(k);
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    if (n == k)
    {
        for (auto &e : v)
        {
            cout << e << " ";
        }
        cout << '\n';
    }
    else
    {
        int temp = 1;
        for (int i = 0; i < k; i++)
        {
            int x = v[i];
            while (x > temp)
            {
                res.push_back(x);
                x--;
            }
            res.push_back(temp);
            temp = v[i] + 1;
        }
        for (auto &e : res)
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
