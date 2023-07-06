#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
ll div_by_2(ll n)
{
    int count = 0;
    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }
    return count;
}


void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v[i] = div_by_2(x);
    }
    ll sum = 0;
    // for(int i=0;i<n/2;i++)
    // {
    //     cout<<div2[i]<<" ";
    // }
    
    // // for (int i = 1; i <= n; i++)
    // // {
    // //     cout << v[i] << " ";
    // // }
    // cout << nline;
    for (int i = 1; i <= n; i++)
    {
        sum += v[i];
    }

    if (sum >= n)
    {
        cout << 0 << nline;
    }
    else
    {
        ll ans = 0;
        bool flag = false;
        vector<ll> v1;
        for (int i = 2; i <= n; i+=2)
        {
           v1.push_back(div_by_2(i));
        }
        sort(v1.begin(), v1.end(),greater<ll>());
        for (int i = 0; i <v1.size(); i++)
        {
            sum += v1[i];
            ans++;
            if (sum >= n)
            {
                flag = true;
                break;
            }
            
        }
        if (flag)
        {
            cout << ans << nline;
        }
        else
        {
            cout << -1 << nline;
        }
    }
    // cout << endl;
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
