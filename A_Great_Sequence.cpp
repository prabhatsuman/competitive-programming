#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    ll n, x;
    cin >> n >> x;
    multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        s.insert(temp);
    }
    ll count = 0;
    for (auto &a : s)
    {
       // cout<<a<<nline;
        if (s.find(a * x) !=s.end())
        {

            auto it=s.find(a*x);
            s.erase(it);
            
        }
        else 
        {
            count++;
        }
        
    }
    cout << count << nline;
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
