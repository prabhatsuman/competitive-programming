#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << nline;
    // }
    bool flag = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m-1; j++)
        {
            int sum = (arr[i][j] - '0' )+ (arr[i + 1][j] - '0') + (arr[i][j + 1] - '0') + (arr[i + 1][j + 1] - '0');
            if(sum==3)
            {
                flag=false;
                break;
            }
        }
    }
    if (flag)
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
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
