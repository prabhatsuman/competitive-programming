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
void solve()
{
    int q;
    cin >> q;
    ll lo = 1, hi = 1e18;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            ll a, b, n;
            cin >> a >> b >> n;
            ll mx = (n - 1) * (a - b) + a;
            ll mi = (n - 1) * (a - b) + b + 1;
            // cout<<mx<<" "<<mi<<nline;
            if (n == 1)
            {
                mx = a;
                mi = 1;
            }
            if (mi > hi || mx < lo)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << 1 << " ";
                lo = max(lo, mi);
                hi = min(hi, mx);
            }
            // cout<<lo<<" "<<hi<<nline;
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll d1 = max(1LL, (ll)(ceil)((lo - l) / ((l - r) * 1.0) + 1));
            ll d2 = max(1LL, (ll)(ceil)((hi - l) / ((l - r) * 1.0) + 1));
            // cout<<d1<<" "<<d2<<nline;
            if (d1 == d2)
            {
                cout << d1 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        // cout<<lo<<" "<<hi<<nline;
    }
    cout << nline;
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
