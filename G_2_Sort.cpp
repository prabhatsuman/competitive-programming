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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> t;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] < 2 * v[i + 1])

        {
            t.push_back(1);
        }
        else
        {
            t.push_back(0);
        }
    }
    // for(int i=0;i<t.size();i++)
    // {
    //     cout<<t[i]<<" ";
    // }
    // cout<<nline;
  
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 0;
        bool flag = false;
        while(t[i]==0 && i<n-1)i++;
        while (count != k && t[i] == 1 && i < n - 1)
        {
            count++;
            i++;
        }
        // cout<<"i: "<<i<<" count: "<<count<<nline;
        if (i != n && count == k)
        {
              ans++;
              flag=true;
        }
          
        while (flag && i < n - 1 && t[i] == 1)
        {
            ans++;
            i++;
        }
    }
    cout << ans << nline;
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