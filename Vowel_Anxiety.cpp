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
    int vc = 0;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
        {
            vc++;
        }
    }
    string temp="";
    vector<pair<string,int>> v;
    for (int i = 0; i < n; i++)
    {
        temp+=s[i];
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
        {
            v.push_back({temp,vc-1});
            temp="";
        }
    }
    for(auto &e : v)
    {
        if(e.second%2==0)
        {
            cout<<e.first;
        }
        else
        {
            for(int i=e.first.size()-1; i>=0; i-- )
            {
                cout<<e.first[i];
            }
        }
    }
    cout<<nline;
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
