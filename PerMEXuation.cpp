#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res;
    if (s[0] == '0' || s[1] == '0' || s[n] == '0')
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int temp = 1;
    res.push_back(0);
    for (int i = 2; i < n; i++)
    {
        if (s[i] == '0')
        {
            res.push_back(i);
        }
        else
        {
            res.push_back(temp);
            temp = i;
        }
    }
    res.push_back(temp);
    for (auto &e : res)
    {
        cout << e << " ";
    }
    cout << '\n';
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
