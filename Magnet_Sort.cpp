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

    int flag = 0, flag1 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        if (s[0] != s[n - 1])
        {
            cout << 1 << '\n';
        }
        else
        {
            char temp = s[0];
            for (int i = 0; i < n; i++)
            {
                if (s[i] != temp)
                {

                    flag1 = 1;
                    break;
                }
            }
            if (flag1 == 0)
            {
                cout << -1 << '\n';
            }
            else
            {
                vector<int> v1 = v;
                sort(v1.begin(), v1.end());
                int start = INT_MAX, end = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    if (v[i] != v1[i])
                    {
                        start = min(start, i);
                        end = max(end, i);
                    }
                }
                bool f1 = false, f2 = false;
                for (int i = 0; i <= start; i++)
                {
                    if (s[i] != s[end])
                    {
                        f1 = true;
                        break;
                    }
                }
                for (int i = end; i < n; i++)
                {
                    if (s[i] != s[start])
                    {
                        f2 = true;
                        break;
                    }
                }
                if (f1 || f2)
                {
                    cout << 1 << '\n';
                }

                else
                {
                    cout << 2 << '\n';
                }
            }
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
