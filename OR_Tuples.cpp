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
    int x, y, z;
    cin >> x >> y >> z;
    if((x==0 && (y!=0 && z!=0))||(y==0 && (x!=0 && z!=0))|| (z==0 && (y!=0 && x!=0)))
    {
        cout<<1<<nline;
        return;
    }
    if((x==0 && y==0 && z!=0)||(y==0 && z==0 && x!=0)|| (z==0 && x==0 && y!=0))
    {
        cout<<0<<nline;
        return;
    }
    if(x==0 && y==0 && z==0)
    {
        cout<<0<<nline;
        return;
    }
    int n = max(max((int)(log2(x)) + 1, (int)(log2(y)) + 1), (int)(log2(z)) + 1);
    // cout<<n<<nline;

    vector<int> p(n), q(n), r(n);
    vector<int> a(n, -1), b(n, -1), c(n, -1);
    int i = 0;
    int t1 = x, t2 = y, t3 = z;
    // cout<<(x&1)<<nline;
    while (x > 0)
    {
        if ((x & 1) == 0)
        {
            a[i] = 0;
            b[i] = 0;
            // cout<<"1"<<nline;
        }
        i++;
        x = x >> 1;
    }
    i = 0;
    while (y > 0)
    {
        if ((y & 1) == 0)
        {
            b[i] = 0;
            c[i] = 0;
        }
        i++;
        y >>= 1;
    }
    i = 0;
    while (z > 0)
    {
        if ((z & 1) == 0)
        {
            a[i] = 0;
            c[i] = 0;
        }
        i++;
        z >>= 1;
    }
    x = t1, y = t2, z = t3;
    i = 0;
    while (x > 0)
    {
        if ((x & 1) == 1)
        {
            if (a[i] == 0)
                b[i] = 1;
            else if (b[i] == 0)
                a[i] = 1;
        }
        i++;
        x >>= 1;
    }
    i = 0;
    while (y > 0)
    {
        if ((y & 1) == 1)
        {
            if (b[i] == 0)
                c[i] = 1;
            else if (c[i] == 0)
                b[i] = 1;
        }
        i++;
        y >>= 1;
    }
    i = 0;
    while (z > 0)
    {
        if ((z & 1) == 0)
        {
            if (a[i] == 0)
                c[i] = 1;
            else if (c[i] == 0)
                a[i] = 1;
        }
        i++;
        z >>= 1;
    }
    // for(auto &e: a)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
    // for(auto &e: b)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
    // for(auto &e: c)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1 && b[i] == -1 && c[i] == -1)
            ans *= 4;
        else if ((a[i] == -1 && (b[i] == 1 || c[i] == 1)) || (b[i] == -1 && (a[i] == 1 || c[i] == 1)) || (c[i] == -1 && (b[i] == 1 || a[i] == 1)))
            ans *= 2;
        else if ((a[i] == -1 && b[i] == -1 && c[i] == 1) || (b[i]==-1 && c[i]==-1 && a[i]==1) || (a[i]==-1 && c[i]==-1 && b[i]==1))ans*=3;
    }
    cout<<ans<<nline;
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