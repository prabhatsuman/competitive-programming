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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // if(n==1)
    // {
    //     cout<<1<<nline;
    //     return;
    // }
    sort(v.begin(), v.end());
    map<int, int> m1,m2;
    for (int i = 0; i < n / 2; i++)
    {
        m1[v[i]]++;
    }
    for(int i=n/2; i<n; i++)
    {
        m2[v[i]]++;
    }
    vector<int> temp1;
    vector<int> temp2;
    for (auto it : m1)
    {
        if(it.second==1)
        {
            temp1.push_back(it.first);
        }
        else
        {
            temp2.push_back(it.first);
            temp1.push_back(it.first);
        }
    }
    for (auto it : m2)
    {
        if(it.second==1)
        {
            temp2.push_back(it.first);
        }
        else
        {
            temp1.push_back(it.first);
            temp2.push_back(it.first);
        }
    }
    set<int> s1,s2;
    for(int i=0; i<temp1.size(); i++)
    {
        s1.insert(temp1[i]);
    }
    for(int i=0; i<temp2.size(); i++)
    {
        s2.insert(temp2[i]);
    }
    // for(auto &e: s1)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
    // for(auto &e: s2)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
    cout<<max(s1.size(),s2.size())<<nline;
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