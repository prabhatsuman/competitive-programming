#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;

    if (n < 3)
    {
        cout << -1 << '\n';
    }
    else if (n % 2 == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout<<'\n';
    }
    else if (n % 2 == 0)
    {
        cout << 2 << " " << 3 << " " << 1 << " " << 4 << " " ;
        for(int i=5; i<=n; i++)
        {
            cout<<i<<" ";
        }
        cout<<'\n';
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
