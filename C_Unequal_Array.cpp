#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = 0;
    int temp = v[0];
    for (int i = 0; i < n; i++)
    {
        if (temp == v[i])
        {
            count++;
        }
        else
        {
            temp = v[i];
        }
    }
    count--;
    int t = 0;
    int i1 = -1, j1 = -1;
    // cout<<count<<nline;
    // cout<<"h"<<nline;
    // if (count == 2)
    // {
    //     cout << 1 << nline;
    //     return;
    // }
    if (count > 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] == v[i + 1] && t < 1)
            {
                i1 = i + 1;
                t++;
                j1 = i + 1;
            }
            if (v[i] == v[i + 1])
            {
                j1 = i + 1;
            }
        }
        cout << max((j1 - i1) - 1,1) << nline;
    }
    else
    {
        cout << 0 << nline;
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
