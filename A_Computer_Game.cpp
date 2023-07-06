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

void dfs(int i, int j, vector<vector<char>> &arr, int n, bool &flag, vector<vector<bool>> &vis)
{

    if (i < 0 || i > 1 || j < 0 || j > n - 1)
        return;
    if (vis[i][j] == true)
        return;
    if (arr[i][j] == '1')
        return;
    vis[i][j] = true;
    // cout << i << " " << j << nline;
    if (i == 1 && j == n - 1)
    {
        flag = true;
        return;
    }
    dfs(i, j + 1, arr, n, flag, vis);
    dfs(i + 1, j, arr, n, flag, vis);
    dfs(i + 1, j + 1, arr, n, flag, vis);
    dfs(i - 1, j + 1, arr, n, flag, vis);
}
void solve()
{
    int n;

    cin >> n;
    vector<vector<char>> arr(2, vector<char>(n));
    bool flag = false;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> dp(2, vector<bool>(n, false));
    dfs(0, 0, arr, n, flag, dp);

    if (flag)
    {
        cout << "YES" << nline;
    }
    else
    {
        cout << "NO" << nline;
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