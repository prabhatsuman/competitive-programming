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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = INT_MAX;
    int count = 0;
    int i = 0;
    int j = 0;
    int c0 = 0, c1 = 0;
    bool f1 = false, f2 = false, f3 = false;
    while (j < n)
    {
        int temp = 0;
        while (s[j] == '0' && j < n && (j - i + 1) <= k)
        {
            j++;
            f1 = true;
        }
        j--;
        if (f1)
        {
            if (s[j - 1] == '1' && f3 && j - 1 >= 0)
            {

                c0++;
            }

            if (!f3)
                c0++;
            f1 = false;
        }

        j++;
        while (s[j] == '1' && j < n && (j - i + 1) <= k)
        {

            j++;
            f2 = true;
        }

        j--;
        if (f2)
        {

            if (s[j - 1] == '0' && f3 && j - 1 >= 0)
                c1++;
            if (!f3)
                c1++;
            f2 = false;
        }

        if (j - i + 1 == k)
        {
            f3 = true;

            if (c0 == 0)
            {
                temp = 0;
            }
            else if (s[j] == '1')
            {
                temp = c0 + c1 - 1;
            }
            else
            {
                temp = c0 + c1;
            }
            ans = min(ans, temp);
            if (s[i] == '1' && s[i + 1] != '1')
            {
                c1--;
            }
            else if (s[i] == '0' && s[i + 1] != '0')
            {
                c0--;
            }

            i++;
        }
        j++;
    }
    if (ans == INT_MAX)
    {
        cout << -1 << nline;
    }
    else
    {
        cout << ans << nline;
    }
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