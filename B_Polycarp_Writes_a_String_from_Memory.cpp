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
    // if(s.size()==1)
    // {
    //     cout<<1<<nline;
    //     return;

    // }
    // else if(s.size()==2)
    // {
    //     cout<<2<<nline;
    //     return;
    // }
    set<char> s1;
    int j = 0, c = 0;
    for (int i = 0; i < s.length();)
    {

        while (s1.size() < 3 && i < s.length())
        {
            s1.insert(s[i]);
            i++;
        }
       // cout << s1.size() << nline;

        if (s1.size() == 3)
        {
            while (s1.find(s[i]) != s1.end())
                i++;
            c++;
           // i--;
            s1.clear();
        }
       // cout << "i " << i << nline;
    }
   //  cout<<s1.size()<<nline;
     if(s1.size()==0)
         cout << c << nline;
     else
         cout<<c+1<<nline;
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
