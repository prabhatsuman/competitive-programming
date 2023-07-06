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
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2)
            odd++;
        else
            even++;
    }
    if ((odd == n && even==0) || (even == n && odd==0))
    {
        cout << 0 << nline;
        return;
    }
    if(odd/2>even)
    {
        cout<<even<<nline;
        return;
    }
    if (odd % 2)
    {
        cout << even << nline;
    }
    else
    {
        cout << odd / 2 << nline;
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
