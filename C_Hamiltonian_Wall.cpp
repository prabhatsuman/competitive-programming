#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
int n;
int black = 0;
int c = 0;
bool flag = false;
vector<vector<bool>> vis(2, vector<bool>(n, false));
void dfs(int i, int j, vector<vector<char>> &a)
{
    if (i < 0 || j < 0 || i >= 2 || j >= n)
        return;
    // if (a[i][j] == 'W')
    //     return;
    if (vis[i][j])
        return;
    vis[i][j] = true;
    if (a[i][j] == 'B')
    {
        c++;
        
       
    }
    //print i,j 
    cout << i << " " << j << nline;
    dfs(i + 1, j, a);
    dfs(i - 1, j, a);
    dfs(i, j + 1, a);
    dfs(i, j - 1, a);
    // if (a[i][j] == 'B')
    //     c--;
}
void solve()
{

    cin >> n;
    vector<vector<char>> a(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // print the array
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << nline;
    // }
    // count B
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'B')
                count++;
        }
    }
    black = count;
    dfs(0, 0, a);
    cout<<c<<nline;
    if (c==black)
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
