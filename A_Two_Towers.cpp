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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int ct1 = 0, ct2 = 0;
    char c1 = '1', c2 = '1';
    int it1 = -1, it2 = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            ct1++;
            if (c1 == '1')
            {
                it1 = i + 1;
                c1 = a[i];
            }
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (b[i] == b[i + 1])
        {
            ct2++;
            if (c2 == '1')
            {
                it2 = i + 1;
                c2 = b[i];
            }
        }
    }
    if (ct1 > 1 || ct2 > 1)
    {
        no;
        return;
    }
    if (ct1 == 1 && ct2 == 0)
    {
        if ((it1 == n - 1 && b[m - 1] != c1) || (it1 != n - 1 && ct1 != a[it1 + 1] && a[n-1]!=b[m-1]))
        {
            yes;
            return;
        }
    }
    if (ct2 == 1 && ct1 == 0)
    {
        if ((it2 == m - 1 && a[n - 1] != c2) || (it2 != m - 1 && ct2 != b[it2 + 1] && b[m-1]!=a[n-1]))
        {
            yes;
            return;
        }
    }
    if (ct1 == 0 && ct2 == 0)
    {
        yes;
        return;
    }
    no;
}

int main()
{
    godspeed;
    ll t;
    cin >> t;

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
    int res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
