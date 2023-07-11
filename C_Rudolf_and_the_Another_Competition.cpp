/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define read(v) for(auto &x:v) cin>>x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    ll n,m,h;
    cin>>n>>m>>h;
    priority_queue<ll,vector<ll>,greater<ll>> pq[n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            ll x;
            cin>>x;
            pq[i].push(x);
        }
    }
    vector<pair<pair<ll,ll>,ll>> v;
    for(ll i=0;i<n;i++)
    {
        ll polls=0, hours=0;
        ll penatly=0;
        while(!pq[i].empty())
        {
            ll x=pq[i].top();
            pq[i].pop();
            if(hours+x<=h)
            {
                penatly+=hours+x;
                hours+=x;
                
                polls++;
            }
            else
            {
                break;
            }
        }
        // cout<<i<<" "<<polls<<" "<<hours<<nline;
        v.pb({{polls,penatly},i});
    }
    sort(all(v),[](pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
        if(a.first.first==b.first.first)
        {
            return a.first.second<b.first.second;
        }
        return a.first.first>b.first.first;
    });
    // for(auto x:v)
    // {
    //     cout<<x.first.first<<" "<<x.first.second<<" " <<x.second<<nline;
    // }
    ll temp=0;
    for(ll i=0;i<n;i++)
    {
        if(v[i].second==0)
        {
            break;
        }
        temp++;
    }
    cout<<temp+1<<nline;

}

int main()
{
    godspeed;
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
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
