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
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == s.back())
    {
        cout << "NO" << nline;
        return;
    }
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    int sum = 0;
    for (auto &e : m)
    {
        sum += e.second;
    }
    bool flag = true;
    if (m[s[0]] != n / 2 && m[s[n - 1]] != n / 2)
    {
        cout << "NO" << nline;
        return;
        flag = false;
    }
    if (flag)
    {
        char a = 'x', b = 'x';
        //cout<<s[0]<<nline;
        if(m[s[0]] == n / 2)
        {
            a = s[0];
        }
        else
        {
            b = s[n - 1];
        }
        //cout << a << nline;
        if (a != 'x')
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == a)
                {
                    s[i] = '(';
                }
                else
                {
                    s[i] = ')';
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == b)
                {
                    s[i] = ')';
                }
                else
                {
                    s[i] = '(';
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            count++;
        else
            count--;
        if (count < 0)
        {
            cout << "NO" << nline;
            return;
        }
    }
    cout << "YES" << nline;
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
