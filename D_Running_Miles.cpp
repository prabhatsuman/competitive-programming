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
// ll solve(ll n, int choice, vl &v, vector<vector<ll>> &dp)
// {

//     if (n < 0)
//     {
//         return -1e18;
//     }
//     if (dp[n][choice] != -1e18)
//     {
//         return dp[n][choice];
//     }
//     ll ans = solve(n - 1, choice, v, dp);
//     if (choice == 0)
//     {
//         ans = max(ans, v[n] + n + 1);
//     }
//     else if (choice == 1)
//     {
//         ans = max(ans, solve(n - 1, 0, v, dp) + v[n]);
//     }
//     else
//     {
//         ans = max(ans, solve(n - 1, 1, v, dp) + v[n] - (n + 1));
//     }
//     return dp[n][choice] = ans;
// }

void solve()
{
    ll n;
    cin >> n;
    vl v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 1][0] + v[i] + i, dp[i - 1][1]);
        dp[i][2] = max(dp[i - 1][1] + v[i], dp[i - 1][2]);
        dp[i][3] = max(dp[i - 1][2] + v[i] - i, dp[i - 1][3]);
    }
    cout << dp[n][3] << nline;
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
