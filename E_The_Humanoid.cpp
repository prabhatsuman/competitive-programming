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
#define read(x)       \
    for (auto &c : x) \
        cin >> c;
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
ll solve(int green, int blue, int n, vector<ll> &arr, ll h)
{
    if (n < 0)
    {
        return 0;
    }
    if (arr[n] < h)
    {
        return 1 + solve(green, blue, n - 1, arr, h + arr[n] / 2);
    }
     if (green == 0 && blue == 0)
        return 0;
    ll ans1 = 0, ans2 = 0;
    if (green > 0)
    {
        ans1 = solve(green - 1, blue, n, arr, h * 2);
    }
    if (blue > 0)
    {
        ans2 = solve(green, blue - 1, n, arr, h * 3);
    }
   
    return max(ans1, ans2);
}

void solve()
{
    ll n, h;
    cin >> n >> h;
    vl v(n);
    read(v);
    sort(v.rbegin(), v.rend());
    ll ans = solve(2, 1, n - 1, v, h);
    print(ans);
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
