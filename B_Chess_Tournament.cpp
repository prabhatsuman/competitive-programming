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
    char arr[n][n];
    int two = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
            two++;
    }
    if (two == 1 || two == 2)
    {
        cout << "NO" << nline;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = i; j < n; j++)
        {
            if (i == j)

            {
                arr[i][j] = 'X';
                continue;
            }
            if (s[i] == '1')
            {
                arr[i][j] = '=';
                arr[j][i] = '=';
                continue;
            }
            if (s[i] == '2' && s[j] == '1')
            {
                arr[j][i] = '+';
                arr[i][j] = '-';
                continue;
            }
            if(s[j] == '2' && s[i] == '1')
            {
                arr[i][j] = '+';
                arr[j][j] = '-';
                continue;
            }
            if (s[i] == '2')
            {
                if (flag)
                {
                    arr[i][j] = '+';
                    arr[j][i] = '-';
                    flag = false;
                }
                else
                {
                    arr[i][j] = '-';
                    arr[j][i] = '+';
                }
            }
        }
    }
    cout << "YES" << nline;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << nline;
    }
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
