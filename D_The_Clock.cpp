#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
bool isPalindrome(string s)
{
    string r = s;
    reverse(s.begin(), s.end());
    return r == s;
}
void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int h = ((s[0] - '0') * 10) + (s[1] - '0'), m = ((s[3] - '0') * 10) + (s[4] - '0');
    int r = n / 60, p = n % 60;
    // cout << h << " " << m << nline;
    // cout << r << " " << p << nline;

    int count = 0;
    //  if (isPalindrome(s))
    //         count++;

    string t = "";
    int c = 5;
    while (t != s)
    {
        string temp = "";

        h = ((h + r) % 24), m = ((m + p));
        if (m / 60 >= 1)
        {
            h++;
        }
        h=h%24;
        m = m % 60;
        // cout << h << " " << m << nline;
        if (h / 10 == 0)
        {
            temp += '0' + to_string(h);
        }
        else
        {
            temp += to_string(h);
        }
        temp += ":";
        if (m / 10 == 0)
        {
            temp += '0' + to_string(m);
        }
        else
        {
            temp += to_string(m);
        }

        t = temp;
       // cout << t << nline;
        if (isPalindrome(t))
            count++;
    }

    // cout << t << nline;

    cout << count << nline;
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
