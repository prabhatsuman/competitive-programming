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
    string a;
    cin >> a;
    string b;
    cin >> b;
    map<char, int> m1, m2;
    set<char> s1, s2;
    for (int i = 0; i < n; i++)
    {
        s1.insert(a[i]);
        s2.insert(b[i]);
        m1[a[i]]++;
        m2[b[i]]++;
    }
    // intersection of two sets
    vector<char> v;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));
    if (v.size() == 0)
    {
        cout << 0 << nline;
        return;
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, min(m1[v[i]], m2[v[i]]));
    }
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
