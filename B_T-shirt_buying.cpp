#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
void sieve();
void solve()
{
    ll n;
    cin >> n;
    vector<ll> price(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    unordered_map<ll, set<pair<ll, ll>>> mp;

    vector<bool> vis(n, false);
    for (ll i = 0; i < n; i++)
    {
        mp[a[i]].insert({price[i], i});
        mp[b[i]].insert({price[i], i});
    }
    ll m;
    cin >> m;
    vector<ll> cust(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> cust[i];
    }
    for (ll i = 0; i < m; i++)
    {
        while (mp[cust[i]].size() > 0 && vis[mp[cust[i]].begin()->second] == true)
        {

            mp[cust[i]].erase(mp[cust[i]].begin());
        }
        if (mp[cust[i]].size() == 0)
        {
            cout << -1 << " ";
            continue;
        }
        auto it = mp[cust[i]].begin();
        cout << it->first << " ";
        vis[it->second] = true;
       
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

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

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= M; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= M; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}