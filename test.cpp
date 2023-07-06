#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
bool check(string s)
{
   
    for (int i = 0; i < s.length(); i++)
    {
        char temp;
        bool found = false;
        if (s[i] >= 'a' && s[i] <= 'z')
            temp = s[i] - 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            temp = s[i] + 32;

        for (int j = 0; j < s.length(); j++)
        {
            //cout<<s<<nline;
            if (temp == s[j])
            {
                //cout<<1<<nline;
                found = true;

                break;
            }
        }
        if (found == false)
        {
            cout<<0<<nline;
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    string ans;
    int len = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        string res = "";
        for (int j = i; j < s.length(); j++)
        {

            res += s[j];
            // cout << res.length() << nline;
            // cout<<res<<nline;
            if (check(res))
            {
                cout << 1 << nline;
                len = res.length();
                ans = res;
            }
        }
    }
    cout << ans << nline;
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
