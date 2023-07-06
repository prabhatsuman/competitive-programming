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
    int n;
    cin >> n;
    string s;
    cin >> s;
    // if (s[0] == 'R' && s[n - 1] == 'L')
    // {
    //     cout << 0 << nline;
    //     return;
    // }
    int lc = 0, rc = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            lc++;
        }
        else
        {
            rc++;
        }
    }
    if (lc == 0 || rc == 0)
    {
        cout << -1 << nline;
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'L' && s[i + 1] == 'R')
        {
            cout << i + 1 << nline; return;
        }
    }
    cout << 0 << nline;
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