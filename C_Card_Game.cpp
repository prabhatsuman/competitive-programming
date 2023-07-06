#include <bits/stdc++.h>
#define ll long long
#define M 998244353
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);

vector<int> loss(60 + 1, 0);
vector<int> win(60 + 1, 1);
unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long ncr(unsigned long long n,
                       int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void precompute()
{
    for (int i = 4; i <= 60; i += 2)
    {
        win[i] = (ncr(i - 1, i / 2 - 1, M) % M + loss[i - 2] % M) % M;
        // cout << ncr(i, i / 2, M) << nline;
        loss[i] = ((((ncr(i, i / 2, M) % M - 1 % M) % M) % M) - (win[i] % M) + M) % M;
    }
}

void solve()
{
    int n;
    cin >> n;

    cout << win[n] << " " << loss[n] << " " << 1 << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
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
