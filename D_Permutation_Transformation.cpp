#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
map<int, int> m;
void divide_array(vector<int> &a, int l, int r, int curr_depth)
{
    if (l > r)
    {
        return;
    }
    int max = INT_MIN;
    int index = -1;
    for (int i = l; i <= r; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    m[max] = curr_depth;

    divide_array(a, l, index - 1, curr_depth + 1);
    divide_array(a, index + 1, r, curr_depth + 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    divide_array(a, 0, n - 1, 0);
    for(int i=0;i<n;i++){
        cout<<m[a[i]]<<" ";
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
