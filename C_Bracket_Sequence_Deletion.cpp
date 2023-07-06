#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    int b = n;
    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] == '(' && s[i + 1] == ')') || (s[i] == '(' && s[i + 1] == '(') || (s[i] == ')' && s[i + 1] == ')'))
        {
            a++;
            b -= 2;
            i++;
        }
        else if (s[i] == ')' && s[i + 1] == '(')
        {
            int len = 2;
            int count =0;
            i+=2;
            while (s[i] != ')' and i < n)
            {
                len++;
                count++;
                i++;
            }
            if (i == n && s[i]!=')')
            {
                break;
            }
            if (s[i] == ')')
            {
                len++;
                a++;
                // cout<<len<<nline;
                // cout<<count<<nline;
                b -= len;
            }
        }
    }
    cout << a << " " << b << nline;
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
