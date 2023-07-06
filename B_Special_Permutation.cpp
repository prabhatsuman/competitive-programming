#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> a1;
    vector<int> a2;
    if ((n - a) + 1 < n / 2 || (b - 1) + 1 < n / 2)
    {
        cout << "-1" << '\n';
    }
    else
    {
        a1.push_back(a);
        for (int i = b + 1; i <= n; i++)
        {
            if (i != a)
                a1.push_back(i);
            if (a1.size() == n / 2)
            {
                break;
            }
        }
        a2.push_back(b);
        for (int i = a - 1; i >= 1; i--)
        {
            if (i != b)
                a2.push_back(i);
            if (a2.size() == n / 2)
            {
                break;
            }
        }
        int temp = a + 1;
        while (a1.size() < n / 2 && temp < b)
        {
            a1.push_back(temp);
            temp++;
        }
        while (a2.size() < n / 2 && temp < b)
        {
            a2.push_back(temp);
            temp++;
        }
        if (a1.size() != n / 2 || a2.size() != n / 2)
        {
            cout << "-1" << '\n';
        }
        else
        {

            for (auto &v1 : a1)
            {
                cout << v1 << " ";
            }
            for (auto &v2 : a2)
            {
                cout << v2 << " ";
            }
            cout << '\n';
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
