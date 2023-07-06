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
    bool flag = true;
    char c = s[0];
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] != c)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << -1 << nline;
        return;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < 2 * n; i++)
    {
        v.push_back({s[i] - '0', i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i].second + 1 << " ";
    }
    cout << nline;
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
