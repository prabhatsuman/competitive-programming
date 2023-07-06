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
    ll n, q;
    cin >> n >> q;
    ll arr[64][n];
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 0; j < 64; j++)
        {
            arr[j][i] = x & 1;
            x = x >> 1;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
            arr[i][j] = sum;
        }
    }
    //print arr
    // for (int i = 0; i < 64; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << nline;
    // }
    

    while(q--)
    {
        ll l1,r1,l2,r2,k;
        cin>>k>>l1>>r1>>l2>>r2;
       
        l1--;
        r1--;
        l2--;
        r2--;
        //  cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<k<<nline;
        // k--;
        ll t1=r1-l1+1;
        ll t2=r2-l2+1;
        ll t11,t22;
        // cout<<t1<<" "<<t2<<nline;
        if(l1==0)
        {
            // cout<<arr[k][r1]<<" ";
            t11=arr[k][r1];
        }
        else
        {
            t11=arr[k][r1]-arr[k][l1-1];
        }
        if(l2==0)
        {
            t22=arr[k][r2];
        }
        else
        {
            t22=arr[k][r2]-arr[k][l2-1];
        }
        ll ans=t11*(t2-t22)+t22*(t1-t11);
        // cout<<t11<<" "<<t22<<" "<<nline;
        cout<<ans<<nline;
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
