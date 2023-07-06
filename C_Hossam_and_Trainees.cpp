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
vector<int> primes;

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= (int)1e5 + 5; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= (int)1e5 + 5; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, bool> mp;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < primes.size(); j++)
        {
            if (primes[j] * primes[j] > v[i])
            {
                break;
            }
            if (v[i] % primes[j] == 0)
            {
                if (mp[primes[j]] == true)
                {
                    flag = true;
                    break;
                }
                else
                {
                    mp[primes[j]] = true;
                }
            }
            while (v[i] % primes[j] == 0)
            {
                v[i] /= primes[j];
            }
        }
        if (v[i] > 1 && mp[v[i]] == true)
        {
            flag = true;
            break;
        }
        else
        {
            mp[v[i]] = true;
        }
        if(flag)
        {
            break;
        }
    }
    if (!flag)
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    for (int i = 1; i <= (int)1e5 + 5; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
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
