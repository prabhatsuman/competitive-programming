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
int n, k, d;
int dp[101][2];
int calc(ll sum, bool flag)
{
    if (sum == 0 && flag == true)
        return 1;
    else if (sum == 0 && flag == false)
        return 0;
    if(sum<0)
        return 0;
    if (dp[sum][flag] != -1)
        return dp[sum][flag];
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i >= d)
            ans = (ans + calc(sum - i, true)) % M;
        else
            ans = (ans + calc(sum - i, flag)) % M;
    }
    return dp[sum][flag] = ans;
}

void solve()
{

    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
   
    cout << calc(n, false) << nline;
    // cout<<dp[0][1]<<nline;
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