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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    for(int i=n-2;i>=0;i--)
    {
        v[i].second=min(v[i].second,v[i+1].second);
    }

    ll sum = k;
    ll index = 0;
    vector<ll> health(n);
    vector<ll> power(n);
    for (int i = 0; i < n; i++)
    {
        health[i] = v[i].first;
        power[i] = v[i].second;
    }

    bool flag = true;
    // ll last = -1;
    while (k > 0)
    {

        auto it = upper_bound(health.begin(), health.end(), sum);

        if (it == health.end())
        {
            cout << "YES" << nline;
            return;
        }
        index = it - health.begin();
        // cout<<"index: "<<index<<nline;

        

        k -= power[index];
        sum += k;
    }
    cout << "NO" << nline;
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