#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<ll, ll> a, r;
    vector<ll> ans;
    for (int i = 0; i < m; i++)
    {
        r[v[i]]++;
    }
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        ll t = r.begin()->first;
        sum += t;
        r[t]--;
        if (r[t] == 0)
        {
            r.erase(t);
        }
        a[t]++;
    }
    ans.push_back(sum);
    for (int i = m; i < n; i++)
    {
        r[v[i]]++;
        ll t = v[i - m];
        if (r.count(t))
        {
            r[t]--;
            if (r[t] == 0)
            {
                r.erase(t);
            }
            ll x=(--a.end())->first;
            ll y=(r.begin())->first;
            if(y<x)
            {
                r[x]++;
                a[x]--;
                if(a[x]==0)
                {
                    a.erase(x);
                }
                r[y]--;
                a[y]++;
                if(r[y]==0)
                {
                    r.erase(y);
                }
                sum+=(y-x);
                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum);
            }
        }
        else
        {
            a[t]--;
            sum-=t;
            if(a[t]==0)
            {
                a.erase(t);
            }
            ll rt=(r.begin())->first;
            r[rt]--;
            if(r[rt]==0)
            {
                r.erase(rt);
            }
            a[rt]++;
            sum+=rt;
            ans.push_back(sum);
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin >> t;
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
