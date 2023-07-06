#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> v1,odd,v2,even;
    for(auto e : v)
    {
        if(e%2)
        {
            v1.push_back(e);
            odd.push_back(e);
        }
        else
        {
            v2.push_back(e);
            even.push_back(e);

        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1==odd && v2==even)
    {
        cout<<"YES"<<nline;
    }
    else
    {
        cout<<"NO"<<nline;
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
