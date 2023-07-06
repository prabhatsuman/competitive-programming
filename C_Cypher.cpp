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
    int q = n;
    vector<int> v(n);
   // vector<string> r(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
         int j=0;
    while (q--)
    {
        int t;
        cin>>t;
        string temp;
        cin>>temp;
       
        int x=v[j];
        for(int i=0; i<t; i++)
        {
            if(temp[i]=='U')
            {
                if(x!=0)
                    x=(x-1);
                else
                    x=9;
            }
            else
            {
                if(x!=9) x++;
                else x=0;
            }
        }
        j++;
        cout<<x<<" ";
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
