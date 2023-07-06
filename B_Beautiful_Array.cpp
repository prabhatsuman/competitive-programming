#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
void seive();

void solve()
{
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<ll> v(n, 0);
    ll req = k * b;
    if (req > s)
    {
        cout << -1 << nline;
        return;
    }
    ll t = (k * (b + 1));
    if (t > 0)
    {
        t--;
    }

    v[n - 1] = min(t, s);
    ll rem = s - v[n - 1];
    // cout << rem << nline;
    ll i = n - 2;
    bool flag = true;
    while (rem > 0)
    {
        if (i < 0 && rem > 0)
        {
            cout << -1 << nline;
            return;
        }
        if (i < 0)
        {
            break;
        }
        if (rem >= k - 1)
        {
            v[i] = k - 1;
            rem -= k - 1;
        }
        else
        {
            v[i] = rem;
            rem = 0;

            break;
        }

        i--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << nline;
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