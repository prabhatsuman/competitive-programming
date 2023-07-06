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
    double n,l;
    cin>>n>>l;
    vector<double> a(n);
    set<double>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    } 
    vector<int> b;
    for(auto i:s){
        b.push_back(i);
    }
    double m=-1;
    for(int i=0;i<b.size()-1;i++)
    {
        if(b[i+1]-b[i]>m)
        {
            m=b[i+1]-b[i];
        }
    }
    double ans=-1;
    if()
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
