#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a * a + b * b == 0)
    {
        cout << 0 << nline;
        return;
    }
    int d = a * a + b * b;
    int i = 0;
    while (i * i < d)
        i++;
    if(d==i*i)
    {
        cout<<1<<nline;
    }
    else if(i*i>d)
    {
        cout<<2<<nline;
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
