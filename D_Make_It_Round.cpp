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
    ll n,m;
    cin>>n>>m;
    ll r=n;
    ll k=1;
    ll cnt2=0,cnt5=0;
    while(n%2==0){
        cnt2++;
        n/=2;
    }
    while(n%5==0){
        cnt5++;
        n/=5;
    }
    while(cnt2<cnt5 && k*2<=m)
    {
        k*=2;
        cnt2++;
    }
    while(cnt5<cnt2 && k*5<=m)
    {
        k*=5;
        cnt5++;
    }
    while(k*10<=m)
    {
        k*=10;
    }
    if(k==1)
    {
        cout<<r*m<<nline;
    }
    else
    {
        ll ans=m/k;
        k*=ans;
        cout<<r*k<<nline;
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