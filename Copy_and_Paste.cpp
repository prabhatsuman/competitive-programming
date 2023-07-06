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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i] - '0';
    }
    if (sum == 0)
    {
        cout << n * m << nline;
        return;
    }
    ll total = sum * m;
    if (total % 2 != 0)
    {
        cout << 0 << nline;
        return;
    }
    else
    {
        if (m % 2 == 0)
        {
            ll last1 = -1, first1 = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    last1 = i;
                    if (first1 == -1)
                    {
                        first1 = i;
                    }
                }
            }
            cout << (n - last1) + first1 << nline;
        }
        else
        {
            ll last1 = -1, first1 = -1;
            ll s1=0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    s1++;
                    
                    if (s1==sum/2)
                    {
                        first1=i;
                    }
                    else if(s1==sum/2+1)
                    {
                        last1=i;
                        break;
                    }
                   
                }
            }
            cout << last1 - first1 << nline;
        }
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
