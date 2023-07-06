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
    vector<int> p1(n, 0);
    vector<int> p2(n, 0);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum1 += v[i];
        p1[i] = sum1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sum2 += v[i];
        p2[i] = sum2;
    }
    int i = 0, j = n - 1;
    bool f = false;
    int count = 1;
    int ans=-1;
    while (i < n && j > 0)
    {

        if (p1[i] == p2[j] && i<j)
        {
            count++;
            f = true;
            ans=max(ans,count);
            i++;
            
        }
        else if (p1[i] > p2[j])
        {
            j--;
            count++;
        }
        else
        {
            i++;
            count++;
        }
    }
    // for (auto &e : p1)
    // {
    //     cout << e << " ";
    // }
    // cout << nline;
    // for (auto &e : p2)
    // {
    //     cout << e << " ";
    // }
    // cout << nline;
    if (f)
    {
        cout << ans << nline;
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
