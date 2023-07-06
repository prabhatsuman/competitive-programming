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
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int arr[n][30] = {0};

    for (int i = 0; i < n; i++)
    {
        int j = 29;
        while (v[i] > 0)
        {
            if (v[i] & 1)
            {
                arr[i][j] = 1;
            }
            j--;
            v[i] = v[i] >> 1;
        }
    }
    int res[30] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            res[j] += arr[i][j];
        }
        // cout<<nline;
    }
    int f[30] = {0};
    for (int i = 0; i < 30; i++)
    {
        if (res[i] > (n - res[i]))
        {
            f[i] = 1;
        }
        else
        {
            f[i] = 0;
        }
    }
    ll a=0;
    for(int i=29; i>=0; i--)
    {
        if(f[i]==1)
        {
            a+=power(2,29-i);
        }
    }
    cout <<a<< nline;
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
