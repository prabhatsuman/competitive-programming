#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll b, c;
    cin >> b >> c;
    ll temp=1;
    if (c % b == 0)
        cout << c / b << '\n';
    else
    {
        temp=lcm(b,c);
        cout<<temp/b<<'\n';
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
