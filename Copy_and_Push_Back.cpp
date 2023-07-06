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
    string t = "";
    t += s[0];
    for (int i = 1, k = 0; i < n, k < n;)
    {
        // cout<<i<<nline;
        string r = "";
        k = k * 2 + 1;
        cout<<"K="<<k<<nline;
        cout<<"I="<<i<<nline;
        for (int j = i; j <= min(k, n - 1); j++)
        {

            r += s[j];
            i++;
        }

       // cout << t << " " << r << nline;
        if (t != r && r.length() != 0)
        {
            // cout << t.length() << " " << r.length() << nline;
            cout << "NO" << nline;
            return;
        }
        k++;
        t += r;
        // i++;
       
            t += s[i];
       
       
        i++;
        // cout<<i<<nline;
    }
    cout << "YES" << nline;
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
