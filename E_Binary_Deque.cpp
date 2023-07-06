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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    vector<pair<int, int>> sums;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int sum = 0;
   // sums.push_back({sum, 0});
    for (int i = 1; i <= n; i++)
    {
        sum += v[i];
        if (sum == 1)
        {
            sums.push_back({sum - 1, i - 1});
        }
        if (v[i] == 1)
        {

            while (v[i + 1] != 1 && i < n)
            {
                i++;
            }
            sums.push_back({sum, i});
        }
    }
    int ans = -1;
    // for (int i = 0; i < sums.size(); i++)
    // {
    //     cout << "{" << sums[i].first << " " << sums[i].second << "} ";
    // }
    // cout << nline;
    for (int i = 1; i < sums.size(); i++)
    {
        pair<int, int> x = make_pair(k + sums[i - 1].first, -1);

        auto j = lower_bound(sums.begin(), sums.end(), x);

        if (j != sums.end())
        {
            //  cout<<ans<<nline;
            if (i > 1)
                ans = max(ans, j->second - (sums[i - 2].second + 1));
            else if(i==1)
                ans = max(ans, j->second);
           // cout << ans << nline;
        }
    }
     ans != -1 ? cout << n-ans << nline : cout << -1 << nline;
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
