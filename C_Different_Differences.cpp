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
    int k, n;
    cin >> k >> n;
    int ans = 1;
    int i = 0;
    int count = 0;
    for (; i < k; i++)
    {
        ans += i;
        cout << ans << " ";
        count++;
        if (n - (ans + i + 1) < k - i - 1)
        {
            break;
        }
    }
    for (int j = count; j < k - 1; j++)
    {
        ans++;

        cout << ans << " ";
    }
    if (count < k)
    {

        if (ans + 1 < n)
        {
            cout << n << " ";
        }
        else
        {
            cout << ans + 1 << " ";
        }
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