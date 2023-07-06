/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 998244353
#define nline '\n'
using namespace std;

int power(int a, int b);
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
int modadd(int a, int b, int m)
{
    return ((a % m) + (b % m)) % m;
}
int modmul(int a, int b, int m)
{
    return ((a % m) * (b % m)) % m;
}
int modsub(int a, int b, int m)
{
    return ((a % m) - (b % m) + m) % m;
}
int moddiv(int a, int b, int m)
{
    return (modmul(a, power(b, m - 2), m) % m);
}

/* -----------------------------Code Begins from here-------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    int m = 998244353;
    vector<int> fib(n + 1, 0);
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        fib[i] = modadd(fib[i - 1], fib[i - 2], m);
    }
    cout<<fib[n]<<nline;
    int ans=modmul(fib[n],power(2,n),m);
    cout << ans << nline;
}

int main()
{
    godspeed;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

int power(int a, int b)
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
