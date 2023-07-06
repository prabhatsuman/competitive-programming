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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<char> v(q);
    map<char, int> m;
    for (int i = 0; i < q; i++)
    {
        cin >> v[i];
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (find(v.begin(), v.end(), s[i]) != v.end())
        {
            res.push_back(i);
        }
    }

    if (res.size() == 0)
    {
        cout << 0 << nline;
        return;
    }
    if (res.size() == 1)
    {
        cout << res[0] << nline;
        return;
    }
    // cout<<res.size()<<nline;
    int ans = res[0];
    for (int i = 0; i < res.size() - 1; i++)
    {
       // cout<<res[i]<<" ";

        ans = max(res[i + 1] - res[i] , ans);
    }
    //  cout<<nline;

    cout << ans << nline;
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
