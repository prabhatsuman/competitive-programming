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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> pre(n);
    vector<int> b(q);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    vector<int> pos(n);
    pos[0] = a[0];
    for (int i = 1; i < n; i++)
        pos[i] = max(pos[i - 1], a[i]);
    for (int i = 0; i < q; i++)
    {
        
        int idx = upper_bound(pos.begin(), pos.end(), b[i]) - pos.begin();
        if (idx == 0)
            cout << 0 << " ";
        else
        {
            idx--;
            cout << pre[idx] << " ";
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