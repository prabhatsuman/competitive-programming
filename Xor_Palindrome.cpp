#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            count++;
        }
        i++;
        j--;
    }
    count % 2 == 0 ? (cout << count/2 << nline) : (cout << (count / 2)+1 << nline);
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
