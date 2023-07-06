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
    int n = s.size();
    if(n==1)
    {
        cout<<"Bob "<<s[0]-'a'+1<<nline;
        return;
    }

   
    if (n % 2 == 0)
    {
        cout << "Alice ";
        int sum = 0;
        for (auto &c : s)
        {
            sum += c - 'a'+1;
        }
        cout << sum << nline;
    }
    else
    {

        int sum = 0,sum1=0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += (s[i] - 'a'+1);
        }
        for (int i = 1; i < n; i++)
        {
            sum1 += (s[i] - 'a'+1);
        }
        if(sum1>sum)
        {
            cout<<"Alice "<<abs(sum1-(s[0]-'a'+1)) <<nline;
        }
        else
        {
            cout<<"Alice "<<abs(sum-(s[n-1]-'a'+1)) <<nline;
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
