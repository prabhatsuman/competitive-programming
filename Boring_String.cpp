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
    // find longest same char substring
    
    map<char, int> m;
    int count = 1;
    int m1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) == m.end())
        {
            m[s[i]] = 1;
            

            while (i<n-1 && s[i] == s[i + 1])
            {
                m[s[i]]++;

                i++;
            }
        }
        else
        {
            int count1 = 1;
            while (i<n-1 && s[i] == s[i + 1])
            {
                count1++;
                i++;
            }
            m1 = max(m1, min(count1, m[s[i]]));
            m[s[i]] = max(m[s[i]], count1);
        }
    }
    // cout<<m1<<nline;
    int m2 = 0;
    for (auto i : m)
    {
        m2 = max(m2, i.second);
    }
    // cout<<m2<<nline;
    if (m2 == 1 && m1 == INT_MIN)
    {
        cout << m2-1 << nline;
        return;
    }
   
    cout << max(m1, m2 - 1) << nline;
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
