#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
void solve()
{
    string s;
    cin >> s;
    ll p;
    cin >> p;
    int n = s.length();
    vector<pair<int, int>> v;
    vector<pair<int, char>> r;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        v.push_back({i, (s[i] - 'a') + 1});
        sum += (s[i] - 'a') + 1;
        r.push_back({i, s[i]});
    }
    //cout << sum << nline;
    sort(v.begin(), v.end(), sortbysecdesc);

    for (int i = 0; i < n; i++)
    {
        if (sum <= p)
            break;

        sum -= v[i].second;
       // cout << v[i].second<< nline;
        r[v[i].first].second = '0';
    }

    for (int i = 0; i < n; i++)
    {
        if(r[i].second!='0')
            cout << r[i].second;
        
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
