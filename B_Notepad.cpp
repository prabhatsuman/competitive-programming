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

    int flag = 0;
    set<pair<char, char>> s1;
    for (int i = 1; i < n; i++)
    {
        pair<char, char> p;
        p.first = s[i - 1];
        p.second = s[i];
        if(s[i]==s[i-1] && s[i-1]==s[i-2] && i>1)
        {
            if(!(s[i]==s[i+1] && i<n-1))
            continue;
        }

        if (s1.find(p) != s1.end())
        {
            flag = 1;
            break;
        }
        else
        {
            s1.insert(p);
        }
    }
    // map<char,set<char>> m;
    // for(int i=0;i<n-1;i++)
    // {

    //     if(m.find(s[i])!=m.end())
    //     {
    //         if(s[i]!=s[i-1] && i>0)
    //         {
    //             if(m[s[i]].find(s[i+1])!=m[s[i]].end())
    //             {
    //                 flag=1;
    //                 break;
    //             }
    //         }

    //         // if(m[s[i]]==*(m[s[i]].find(s[i+1])) && s[i]!=s[i-1] && i>0)
    //         // {
    //         //     flag=1;
    //         //     break;
    //         // }
    //         else if(s[i]==s[i-1] && s[i]==s[i+1])
    //         {
    //             if(s[i+1]==s[i+2] && i<n-2)
    //             {
    //                 flag=1;
    //                 break;
    //             }

    //         }
    //     }
    //     else
    //     {
    //         m[s[i]].insert(s[i+1]);
    //     }
    // }
    if (flag == 1)
    {
        cout << "YES" << nline;
    }
    else
    {
        cout << "NO" << nline;
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
