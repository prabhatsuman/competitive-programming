/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/

void solve()
{
    ll n, q;
    cin >> n >> q;
    map<ll, ll> row, col;
    set<ll> row1, col1;
    for (int i = 1; i <= n; i++)
    {
        row1.insert(i);
        col1.insert(i);
    }
    while (q--)
    {
        ll t;
        cin >> t;

        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            row1.erase(x);
            col1.erase(y);
            row[x]++;
            col[y]++;
        }
        if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            row[x]--;
            col[y]--;
            if (row[x] == 0)
            {
                row.erase(x);
                row1.insert(x);
            }
            if (col[y] == 0)
            {
                col.erase(y);
                col1.insert(y);
            }
        }
        if (t == 3)
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto it1 = row1.lower_bound(x1);
            auto it2 = col1.lower_bound(y1);
            // cout << "It1 :" << *it1 << nline;
            // cout << "it2 :" << *it2 << nline;
            if ((it1 != row1.end() && *it1 <= x2) && (it2 != col1.end() && *it2 <= y2))
            {
                no;
                continue;
            }

            // if (it2 != col1.end() && *it2 <= y2)
            // {
            //     no;
            //     continue;
            // }
            yes;
        }
    }
}

int main()
{
    godspeed;
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
