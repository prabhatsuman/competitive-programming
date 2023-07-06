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
int n, s;
int dp[1001][1001];
string solve(int n, int s)
{
    if (n == 0)
    {
        return "";
    }
    if (s > 8)
    {
        return "9" + solve(n - 1, s - 9);
    }
    else
    {
        return to_string(s) + solve(n - 1, 0);
    }
}

void solve()
{
    cin >> n >> s;
    if(s==0 && n==1)
    {
        cout<<0<<" "<<0<<nline;
        return;
    }
    if (s == 0 && n > 1)
    {
        cout << -1 << " " << -1 << nline;
        return;
    }
    if (s > 9 * n)
    {
        cout << -1 << " " << -1 << nline;
        return;
    }
    string res = solve(n, s);
    string res2 = res;
    reverse(all(res));

    bool flag = false;
    if (res[0] == '0')
    {
        res[0] = '1';
        flag = true;
    }

    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] != '0' && flag)
        {
            res[i] = (--res[i]);
            flag = false;
        }
    }
    cout << res << " ";
   
    cout << res2 << nline;
}

int main()
{
    godspeed;
    ll t = 1;
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
