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
    ll n;
    cin >> n;
    bool f = true;
    ll pos = 0, neg = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < 0)
            neg++;
        else if (v[i] > 0)
            pos++;
    }
    sort(v.begin(), v.end());
    if (pos > 2 || neg > 2)
    {
        f = false;
    }

    else
    {
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != 0)
                r.push_back(v[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                r.push_back(v[i]);
                break;
            }
        }
        int t = r.size();

        int i, j, k;
        for (i = 0; i < t; i++)
        {
            ll sum = 0;
            for (j = i + 1; j < t; j++)
            {
                for (k = j + 1; k < t; k++)
                {

                    sum = r[i] + r[j] + r[k];
                    if (find(r.begin(), r.end(), sum) == r.end())
                        f = false;
                    if (!f)
                        break;
                }
                if (!f)
                    break;
            }
            if (!f)
                break;

            // cout << sum << nline;
        }
    }
    if (f)
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
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
