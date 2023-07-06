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
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
#define print2d(v) for (int i = 0; i < v.size(); i++) { for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " "; cout << nline; }
#define printp(v) for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << nline;
#define printm(m) for (auto it = m.begin(); it != m.end(); it++) cout << it->first << " " << it->second << nline;
#define prints(s) for (auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;

#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/

    
void solve()
{
    ll x,y;
    cin>>x>>y;
    if(x==y)
    {
        cout<<x<<nline;
        return;
    }
    vector<int> bit1(64,0),bit2(64,0);
    int count=0;
    while(x>0)
    {
        bit1[count++]=x&1;
        x>>=1;
    }

    count=0;
    while(y>0)
    {
        bit2[count++]=y&1;
        y>>=1;
    }
    // printv(bit1);
    // cout<<endl;
    // printv(bit2);
    for(int i=0;i<64;i++)
    {
        if(bit1[i]==0 && bit2[i]==1)
        {
            cout<<-1<<nline;
            return;
        }
    }
    int ind=-1;
    for(int i=63;i>=0;i--)
    {
        if(bit1[i]==1 && bit2[i]==0)
        {
            ind=i;
            break;
        }
    }
    // print(ind);
    if(bit2[ind+1]==1)
    {
        cout<<-1<<nline;
        return;
    }
    for(int i=ind-1;i>=0;i--)
    {
        if(bit2[i]==1)
        {
            cout<<-1<<nline;
            return;
        }
    }
    ll ans=0;
    for(int i=63;i>ind+1;i--)
    {
        if(bit1[i]==1)
            ans+=power(2,i);
    }
    ans+=power(2,ind+1);
    cout<<ans<<nline;
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
        return (a * (res * res));
    }
    else
    {
        return (res * res);
    }
}

