#include <bits/stdc++.h>
#define ll long long
#define M 998244353
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll count1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            count1++;
        }
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    for(int i=0;i<n;i++){
        if(a[i]%2==0 && count1>0){
            b.push_back(a[i]+1);
            count1--;
        }
        else{
            b.push_back(a[i]);
        }
       
    }
    ll prod = 1;
    for(int i=0;i<b.size();i++){
        prod = (prod*b[i])%M;
    }
    cout<<prod%M<<nline;


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
