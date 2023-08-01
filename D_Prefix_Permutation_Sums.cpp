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
bool isPermutation(int n, vl &nums)
{
    sort(all(nums));
    for (int i = 1; i <= n; i++)
    {
        if (nums[i - 1] != i)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vl v(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    ll last = n * 1LL*(n + 1) / 2;
    if (v[n - 2] > last)
    {
        no;
        return;
    }
    if (v[n - 2] != last)
    {
        v.push_back(last);
    }

    vl diff;
    diff.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        diff.push_back(v[i] - v[i - 1]);
    }

    if (diff.size() == n)
    {
        if (isPermutation(n, diff))
        {
            yes;
            return;
        }
        else
        {
            no;
            return;
        }
    }
    set<ll> s(all(diff));
    vl miss;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
            miss.pb(i);
    }
    // printv(miss);
    // cout << endl;
    if (miss.size() != 2)
    {
        no;
        return;
    }
    if (s.find(miss[0] + miss[1]) != s.end())
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
