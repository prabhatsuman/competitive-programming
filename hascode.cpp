#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    unordered_map<string, int> m;
    while (n--)
    {
        int k;
        cin >> k;
        while (k--)
        {
            string s;
            cin >> s;
            m[s]++;
        }
        int h;
        cin >> h;
        while (h--)
        {
            string in;
            cin >> in;
            m[in]--;
        }
    }

    for (auto &p : m)
    {
        cout << p.first << " " << p.second << '\n';
    }
    for (pair<string, int> p : m)
    {
        if (p.second > 0)
        {
            cout << p.first << " ";
        }
    }
    int ct = 0;
    for (pair<string, int> p : m)
    {
        if (p.second > 0)
        {
            ct++;
        }
    }
    cout << ct << " ";
    return 0;
}