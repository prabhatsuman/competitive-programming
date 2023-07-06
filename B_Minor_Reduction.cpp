#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') + (s[i - 1] - '0') > 9)
        {
            s[i] =( ((s[i] - '0') + (s[i - 1] - '0')) %10)+48;
            s[i - 1] = '1';
            c = 1;
            break;
        }
    }
    if (c == 0)
    {
        s[1] = (s[0] - '0') + (s[1] - '0')+48;
        s[0] = '0';
    }
    if(s[0]=='0')
    {
        s.erase(0,1);
        cout<<s<<nline;
    }
    else
    {
        cout<<s<<nline;
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

