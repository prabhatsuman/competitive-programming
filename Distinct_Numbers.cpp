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
    int n, k;
    cin >> n >> k;
    int r = k;
    vector<int> v(2 * n + 1, 0);
    int m = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        m = max(m, x);

        v[x]++;
    }
    int x = m;
    ll ans1 = 0;

    for (int i = 2 * n; i >= 1; i--)
    {
        m = max(m, i);
        if (v[i] == 0)
        {

            ans1 += m - i;

            k--;
        }
        if (k == 0)
        {
            break;
        }
    }
    k = r;
    m = x;
    ll ans2 = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        m = max(m, i);
        if (v[i] == 0)
        {

            ans2 += m - i;

            k--;
        }
        if (k == 0)
        {
            break;
        }
    }

    cout << max(ans1, ans2) << nline;
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