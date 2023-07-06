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
    int s1 = n-1, s2 = 0;
    int c1=0;
    for (int i = n-1; i >0; i--)
    {
        
        if (s[i] == '1')
        {
            break;
        }
        s1--;
    }
    for (int i = 0; i < n-1; i++)
    {
      
        if (s[i] == '0')
        {
            
            break;
            
        }
          s2++;
    }
    cout<<s1<<" "<<s2<<nline;
    cout<<abs(s1-s2)+1<<nline;
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
