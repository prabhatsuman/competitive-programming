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
    bool flag = false;
    bool f1=false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << 0 << nline;
    }
    else
    {

        for (int i = 0; i < n - 1; i++)
        {
            if ( s[i]=='1' && s[i+1]=='1')
            {
               f1=true;
               break;
            }
            
        }
        if(f1)
        {
            cout<<2<<nline;
        }
        else
        {
            cout<<1<<nline;
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
