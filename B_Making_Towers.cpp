#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
int n;
vector<int> v[100100];
void answer(int x)
{

    if (!v[x].size())
    {
        cout << 0 << " ";
        return;
    }

    int curr = v[x][0];
    int ans = 1;

    for (int i : v[x])
    {
        if ((i & 1) != (curr & 1))
        {
            ans++;
            curr = i;
        }
    }

    cout << ans << " ";
}
void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
    }

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)

    {
        answer(i);
        
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
