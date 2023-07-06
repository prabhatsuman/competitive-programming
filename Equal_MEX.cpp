#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(2 * n);
    set<int> s1;
    map<int, int> m;
    int flag = 0;
    int flag1 = 0;
    int flag2 = 0;
    int check = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        int temp = v[i];
        s1.insert(temp);
        m[temp]++;
    }
    int c = 0;
    for (auto &s : s1)
    {

        if (s != c)
        {
            check=c;
            flag = 1;
            break;
        }
        
        c++;
    }

    if (flag == 1)
    {
        if (check != 0)
        {
            for (int i = 0; i < check; i++)
            {
                if (m[i] < 2)
                {
                    flag1 = 1;
                    break;
                }
            }
        }

        if (flag1 == 1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
    else
    {
        for (auto &m1 : m)
        {
            if (m1.second < 2)
            {
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
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
