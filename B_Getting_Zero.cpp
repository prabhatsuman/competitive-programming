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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = INT_MAX;
        if (v[i] == 0)
            cout << 0 << " ";
        else
        {

            for (int j = 0; j <= 15; j++)
            {
                int temp = v[i] + j;
                int p2 = 0;
                while (temp > 0)
                {
                    if (temp % 2 == 0)
                    {
                        p2++;
                        temp /= 2;
                    }
                    else
                    {
                        break;
                    }
                }

                int t2 = 15 - p2;
                t2 += j;
                count = min(count, t2);
            }
            cout << count << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;

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
