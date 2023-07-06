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
    int c1 = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            while (s[i] == '1')

            {
                i++;
            }
            i--;
            if (i != n - 1)
                c1++;
        }
    }
    // int j = n - 1;
    // while (s[j] == '1' && j >= 0)
    // {
    //     j--;
    //     c1--;
    // }
    // int c = 0;
    // for (int i = j; i >= 0; i--)
    // {
    //     while (s[i] == '1')
    //     {
    //         if (c > 1)
    //         {

    //             c1--;
    //             i--;
    //         }
    //         c++;
    //     }
    //     c=0;
    //     // c1++;

    cout << c1 << nline;
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
