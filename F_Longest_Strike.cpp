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
    vector<int> v(n);
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
        s.insert(v[i]);
    }
    vector<int> res;
    for (auto e : s)
    {
        if (m[e] >= k)
            res.push_back(e);
    }
    // for (auto &e : res)
    // {
    //     cout << e << " ";
    // }
    // cout << nline;
    if (res.size() == 0)
    {
         cout << -1 << nline;
    }
    else
    {
        int start = res[0], end = res[0];
        int temp = res[0];
        map<int, pair<int, int>> r;
        for (int i = 0; i < res.size(); i++)
        {
            if (temp == res[i])
            {
                end = res[i];
            }
            else
            {
                r.insert({end - start + 1, {start, end}});
                start = res[i];
                 end = res[i];
                temp = res[i];
            }
            temp++;
        }
        r.insert({end - start + 1, {start, end}});

        
         cout<<(--r.end())->second.first<<" "<<(--r.end())->second.second<<nline;
        // cout<<start<<" "<<end<<nline;
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
