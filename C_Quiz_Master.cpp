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
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    multiset<int> s;
    vi vis(m + 1, -1);
    int count = 0;
    int ans = INT_MAX;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j * j <= v[i]; j++)
        {
            int a = -1, b = -1;
            if (v[i] % j == 0)
            {
                a = j;
                if (j != v[i] / j)
                    b = v[i] / j;
            }
            if (a >= 1 && a <= m)
            {
                if (vis[a] == -1)
                {
                    vis[a] = v[i];
                    count++;
                    s.insert(v[i]);
                }
                else
                {
                    if (s.find(vis[a]) != s.end())
                        s.erase(s.find(vis[a]));
                    vis[a] = v[i];
                    s.insert(v[i]);
                }
            }
            if (b >= 1 && b <= m)
            {

                if (vis[b] == -1)
                {
                    vis[b] = v[i];
                    count++;
                    s.insert(v[i]);
                }
                else
                {
                    if (s.find(vis[b]) != s.end())
                        s.erase(s.find(vis[b]));
                    vis[b] = v[i];
                    s.insert(v[i]);
                }
            }
        }
        if (count == m)
        {
            flag = true;
            ans = min(ans, *s.rbegin() - *s.begin());
        }
    }
    if (flag)
    {
        print(ans);
    }
    else
    {
        print(-1);
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