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
    vector<int> v;
    int i = 1, j = n * n;
    while (i < j)
    {
        v.push_back(i);
        v.push_back(j);
        i++;
        j--;
    }
    if (n & 1)
    {
        v.push_back(i);
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));
    int c = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = v[k];
                k++;
            }
            c = 1;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                ans[i][j] = v[k];
                k++;
            }
            c = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << nline;
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