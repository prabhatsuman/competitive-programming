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
    ll n;
    cin >> n;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push({x, i + 1});
    }
    vector<pair<ll, ll>> ans;
    // auto it = pq.top();
    // print priority queue

    ll count = 0;
    ll r = 3;
    while (pq.size()!=1)
        {
            // if(r==0)
            // {
            //     break;
            // }
            // r--;

            pair<ll, ll> p = pq.top();
            // cout << "p.first : " << p.first << nline;
            // cout<<"p.second : "<<p.second<<nline;
            pq.pop();
            pair<ll, ll> p1 = pq.top();
            // cout << "p1.first : " << p1.first << nline;
            // cout<<"p1.second : "<<p1.second<<nline;
            // cout<<p.first<<" "<<p1.second<<nline;
            // cout<<p1.first<<" "<<p1.second<<nline;
            if (p1.first % p.first != 0)
            {
                count++;
                ans.push_back({p1.second, p.first - (p1.first % p.first)});
                pq.pop();
                // cout<<( (p.first % p1.first))<<nline;
                pq.push({p1.first + (p.first - (p1.first % p.first)), p1.second});
                pq.push(p);
            }
            else
            {
                continue;
            }
        }
    cout << ans.size() << nline;
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << nline;
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
