#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout<<"YES"<<nline;
        for (int i = 1; i <= n; i++)
        {
            cout << i << nline;
        }
        return;
    }
    if (n % 2 )
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
        int odd = 1, even = 2, c = 0;
        int t1=0,t2=0;
        int c1=0,c2=0;
        for (int i = 1; i <= n; i++)
        {
            if (c == 0)
            {
                for (int j = odd; c1 <k; j += 2)
                {
                    cout << j << " ";
                    t1=j;
                    c1++;
                }
                cout << nline;
                odd = t1+2;
                c = 1;
                c1=0;
            }
            else
            {
                for (int j = even; c2 < k; j += 2)
                {
                    cout << j << " ";
                    t2=j;
                    c2++;
                }
                cout << nline;
                even = t2+2;
                c = 0;
                c2=0;
            }
            

            
        }
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
