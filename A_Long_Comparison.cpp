#include <bits/stdc++.h>
#define ll long long
#define nline '\n'
using namespace std;
void solve()
{
    int x1, p1;
    cin >> x1 >> p1;
    int x2, p2;
    cin >> x2 >> p2;
    ll n1 = 0, n2 = 0;
    string s1 = to_string(x1);
    string s2 = to_string(x2);
    n1 = s1.length();
    n2 = s2.length();
    ll c1 = n1 + p1;
    ll c2 = n2 + p2;
    if (c1 > c2)
    {
        cout << ">" << nline;
    }
    else if (c1 < c2)
    {
        cout << "<" << nline;
    }
    else
    {
        ll i = 0;
        for (i = 0; i < min(n1, n2); i++)
        {
            if (s1[i] > s2[i])
            {
                cout << ">" << nline;
                return;
            }
            else if (s1[i] < s2[i])
            {
                cout << "<" << nline;
                return;
            }
        }
        if (n1 > n2)
        {
            while (i < n1)
            {
                ll temp = s1[i++] - '0';
                if (temp > 0)
                {
                    cout << ">" << nline;
                    return;
                }
            }
            cout << "=" << nline;
        }
        else
        {
            while (i < n2)
            {
                ll temp = s2[i++] - '0';
                if (temp > 0)
                {
                    cout << "<" << nline;
                    return;
                }
            }
            cout << "=" << nline;
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
