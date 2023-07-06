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
    string s;
    cin>>s;
    map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    if(m.size()==1)
    {
        print(-1);
        return;
    }
    if(m.size()>2)
    {
        print(4);
        return;
    }
    if(m.size()==2)
    {
        int a=m.begin()->second;
        int b=m.rbegin()->second;
        if(a==b)
        {
            print(4);
            return;
        }
        else
        {
            print(6);
            return;
        }
    }

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

