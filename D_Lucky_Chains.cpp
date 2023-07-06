#include <bits/stdc++.h>
#define ll long long
#define M (int)1e7+5
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M + 1, 1);
typedef vector<ll> vi;
#define all(v) (v).begin(), (v).end()
vector<ll> min_prime(M + 1, 0);
void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= M; i++)
    {

        if (isPrime[i] == true)
        {
            // min_prime[i] = i;
            for (ll j = i; j <= M; j += i)
            {
                isPrime[j] = false;
                if (min_prime[j] == 0)
                    min_prime[j] = i;
            }
        }
    }
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x == y)
    {
        if (x == 1)
        {
            cout << 1 << nline;
        }
        else
        {
            cout << 0 << nline;
        }
    }
    else if (y - x == 1)
    {
        cout << -1 << nline;
    }
    else
    {
        ll x1 = INT_MAX;
        // cout<<x1<<nline;
        ll diff = y - x;
        // cout<<"diff: "<<diff<<nline;
        while (min_prime[diff] != 0)
        {
            ll p = min_prime[diff];
            // cout<<"p: "<<p<<nline;
            
            if (x % p == 0)
            {
                x1 = x;
            }
            else
            {
                x1 = min(x1, (x / p + 1) * p);
            }
            while (diff % p == 0)
                diff /= p;
        }
        // cout<<x1<<nline;
        cout << x1 - x << nline;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
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