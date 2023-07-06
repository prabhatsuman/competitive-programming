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
void seive();

void solve()
{
    int n;
    cin >> n;
    multiset<int> m;
    vi a(n), b(n), m1, m2(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        m.insert(b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int x = *(lower_bound(all(b), a[i])) - a[i];
        m1.push_back(x);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int mm = *m.rbegin() - a[i];
        m.erase(m.lower_bound(a[i]));
        
        m2[i] = mm;
    }
    for (auto &e : m1)
    {
        cout << e << " ";
    }
    cout << endl;

    for (auto &e : m2)
    {
        cout << e << " ";
    }
    cout << endl;
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