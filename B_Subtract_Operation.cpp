#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n, k;
    cin >> n >> k;
    bool flag = false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // for (auto &e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << nline;
    int i = 0;
    int j = 1;
    while (i < n and j < n)
    {

        if (v[j] - v[i] == k)
        {
            flag = true;
            break;
        }
        else if (v[j] - v[i] < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    if (flag)
    {
        cout << "YES" << nline;
    }
    else
    {
        cout << "NO" << nline;
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
