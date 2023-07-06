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
// using sieve compute primes upto 10^6
const int N = 1e6 + 5;
vector<bool> isPrime(N, true);
vector<int> primes;
// void sieve()
// {

//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i * i <= N; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i * i; j <= N; j += i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     for (int i = 2; i <= N; i++)
//     {
//         if (isPrime[i])
//             primes.push_back(i);
//     }
// }
ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans = (ans * i);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    unordered_map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }
    v.clear();
    for (auto it = s.begin(); it != s.end(); it++)
    {
        v.push_back(*it);
    }
    n = v.size();
    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second >= 3)
        {
            ll r = it->second;
            ans += r * (r - 1) * (r - 2)*1LL;
            // m[it->first] = it->second % 3;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j * j <= v[i]; j++)
        {
            if (v[i] % j == 0)
            {
                ll x = v[i] / j;

                if (m[x])
                {
                    if (x % j == 0)
                    {

                        ll y = x / j;

                        if (m[y])
                        {
                            ans += m[v[i]] * m[x] * m[y]*1LL;
                        }
                    }
                }
            }
        }
    }
    cout << ans << nline;
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
