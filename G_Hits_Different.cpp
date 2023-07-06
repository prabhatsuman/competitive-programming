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

vector<vector<pair<ll, ll>>> adj(1416, vector<pair<ll, ll>>(1416, {0, 0}));
unordered_map<ll, pair<ll, ll>> mp;
void precompute()
{
    ll temp = 4;
    adj[1][1].first = 1;
    adj[1][1].second = 1;
    adj[2][1].first = 2;
    adj[2][1].second = 5;
    adj[2][2].first = 3;
    adj[2][2].second = 10;
    mp[1] = {1, 1};
    mp[2] = {2, 1};
    mp[3] = {2, 2};
    for (int i = 3; i <= 1415; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
            {
                adj[i][j].second += adj[i - 1][j - 1].second;
            }
            else if (j == 1)
            {
                adj[i][j].second += adj[i - 1][j].second;
            }
            else
            {

                adj[i][j].second += adj[i - 1][j - 1].second;
                adj[i][j].second += adj[i - 1][j].second;
                adj[i][j].second -= adj[i - 2][j - 1].second;
            }
            adj[i][j].second += temp * temp;
            mp[temp] = {i, j};

            adj[i][j].first = temp;
            temp++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    pair<ll, ll> p = mp[n];
    cout << adj[p.first][p.second].second << nline;
}

int main()
{
    godspeed;
    precompute();
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
