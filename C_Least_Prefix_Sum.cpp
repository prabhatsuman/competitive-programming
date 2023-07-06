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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << nline;
        return;
    }
    ll t = 0;

    ll ans = 0;

    priority_queue<ll> pq;
    for (ll i = m; i > 1; i--)
    {
        t += a[i];
        if (a[i] > 0)
            pq.push(a[i]);

        while (t > 0)

        {   
            if(pq.empty())
                break;
            ll x = pq.top();
            pq.pop();
            t -= 2 * x;
            ans++;
        }
    }

    t = 0;

    priority_queue<ll> pq1;
    for (ll i = m + 1; i <= n; i++)
    {

        t += a[i];
        if (a[i] < 0)
        {
            pq1.push(-a[i]);
        }

        while (t < 0)
        {
            if(pq1.empty())
                break;

            ll x = pq1.top();
            pq1.pop();
            t += 2 * x;

            ans++;
        }
    }
    cout << ans << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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