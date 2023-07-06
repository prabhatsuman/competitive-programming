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
    
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    if(n%2)
    {
        cout<<"NO"<<nline;
        return;
    }
    sort(res.begin(), res.end());
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n / 2; i++)
    {
        v1.push_back(res[i]);
    }
    for (int i = (n / 2); i < n; i++)
    {
        v2.push_back(res[i]);
    }
    vector<int> v;
    
    int r = v1.size() - 1, s = v2.size();
    for (int i = 0, j = 0; i <= r && j <s; i++, j++)
    {
        v.push_back(v1[i]);
        v.push_back(v2[j]);
    }
    if (n % 2 == 1)
    {
        v.push_back(v2.back());
    }

    // cout << "v1" << nline;
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << nline;
    // cout << "v2" << nline;
    // for (int i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << " ";
    // }
    // cout << nline;
    // cout << "res" << nline;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nline;
    bool f = true;
    for (int i = 0; i < n ; i++)
    {
        if(i==0)
        {
            if(v[i]>=v[i+1] && v[i]<=v[n-1])
            {
                f=false;
            }
            else if(v[i]<=v[i+1] && v[i]>=v[n-1])
            {
                f=false;
            }
        }
        else if(i==n-1)
        {
             if(v[i]>=v[0] && v[i]<=v[i-1])
            {
                f=false;
            }
            else if(v[i]<=v[0] && v[i]>=v[i-1])
            {
                f=false;
            }
        }
        else
        {
             if(v[i]>=v[i+1] && v[i]<=v[i-1])
            {
                f=false;
            }
            else if(v[i]<=v[i+1] && v[i]>=v[i-1])
            {
                f=false;
            }
        }
    }
    if (f)
    {
        cout << "YES" << nline;
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << nline;
    }
    else
    {
        cout << "NO" << nline;
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
