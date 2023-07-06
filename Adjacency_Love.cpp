#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    int t = odd, u = even;
    int o = -1, e = -1;
    if (odd % 2 == 0 && odd > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 1)
            {
                res.push_back(v[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                res.push_back(v[i]);
            }
        }
        for (auto &ele : res)
        {
            cout << ele << " ";
        }
    }
    else if (odd % 2 == 1 && even > 0 && odd > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (t == 1 && v[i] % 2 == 1)
            {
                o = v[i];
                break;
            }
            if (v[i] % 2 == 1)
            {
                res.push_back(v[i]);
                t--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (u == 1 && v[i] % 2 == 0)
            {
                e = v[i];
                break;
            }
            if (v[i] % 2 == 0)
            {
                res.push_back(v[i]);
                u--;
            }
        }

        res.push_back(e);
        res.push_back(o);
        for (auto &ele : res)
        {
            cout << ele << " ";
        }
    }

    else if (odd % 2 == 1 && even == 0)
    {
        cout << "-1";
    }
    else if (odd == 0 || odd == 1)
    {
        cout << "-1";
    }
    cout << nline;
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
