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
    string s;
    cin >> s;
    map<int, int> dis;
    map<int, int> l;

    int c_d = 0, c_l = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            dis.insert({v[i], i});
            c_d++;
        }
        else if (s[i] == '1')
        {
            l.insert({v[i], i});
            c_l++;
        }
    }
    int t1 = 1;
    for (auto &p : dis)
    {
        v[p.second] = t1;
        t1++;
    }
    int t2 = c_d + 1;
  
    for (auto &p : l)
    {
        v[p.second] = t2;
        t2++;
    }
    for (auto &ele : v)
    {
        cout << ele << " ";
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
