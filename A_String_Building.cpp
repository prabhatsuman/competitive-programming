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
    int n=s.length();
    if (s.size() == 1)
    {
        cout << "NO" << nline;
        return;
    }

    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'a')
        {
            cout << "NO" << nline;
            return;
        }
       if(s[i]=='b' && s[i+1]=='a' && s[i+2]=='b')
       {
            cout << "NO" << nline;
            return;
       }
    }
    if(s[n-2]=='a' && s[n-1]=='b')
    {
        cout << "NO" << nline;
        return;
    }
    else if(s[n-2]=='b' && s[n-1]=='a')
    {
        cout << "NO" << nline;
        return;
    }
    else if(s[0]=='a' && s[1]=='b')
    {
        cout << "NO" << nline;
        return;
    }
    else if(s[0]=='b' && s[1]=='a')
    {
        cout << "NO" << nline;
        return;
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
