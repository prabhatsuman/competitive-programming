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
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
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
bool check(vpi &v, vi &temp, int mid, int n)
{
    vi ans(n + 1, 0);
    for (int i = 0; i <= mid; i++)
    {
        ans[temp[i]] = 1;
    }
   
    vi pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + ans[i];
    }
    for (auto it : v)
    {
        int t = (it.second - it.first + 1) / 2 + 1;
        if (pre[it.second] - pre[it.first - 1] >= t)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vpi v(m);
    for (auto &x : v)
    {
        cin >> x.first;
        cin >> x.second;
    }
    int q;
    cin >> q;
    vi temp(q);
    read(temp);

    int lo = 0, hi = q - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (check(v, temp, mid, n))
        {

            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
   
    if (check(v, temp, lo, n))
    {

        cout << lo + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
