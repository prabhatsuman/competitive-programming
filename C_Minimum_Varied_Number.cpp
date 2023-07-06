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
    if(n<=9)
    {
        cout<<n<<nline;
        return;
    }
    set<int> s;
    vector<bool> v(10, false);
    int r = 9;

    while (n > 0)
    {
        n -= r;
        s.insert(r);
        v[r] = true;
        // if(v[n]==false)
        // {
        //     s.insert(n);
        //     break;
        // }
        if(n<=9 && v[n]==false)
        {
            s.insert(n);
            break;
        }
        r--;
    }

    for (auto &e : s)
    {
        cout << e;
    }
    cout << nline;
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
