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
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    unordered_set<string> s;
    for (int i = 0; i < n; i++)

    {
        s.insert(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int x = v[i].length();
        string t1 = "", t2 = "";
        int j = 0;
        bool f=false;
        for (j = 0; j < x - 1; j++)
        {
            t1 += v[i][j];
            for (int k = j+1; k < x; k++)
            {
                t2+=v[i][k];
            }
            if(s.find(t1)!=s.end() && s.find(t2)!=s.end())
            {
                f=true;
                break;
            }
            else
            {
                t2="";
            }
        }
        if(f)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
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
