#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int temp = n;
    temp /= 10;
    int rem = temp % 10;
    int k = n % 7;
    int a = n - k;
    int b = (7 - k) + n;
    int temp1 = a;
    int temp2 = b;
    temp1 /= 10;
    temp2 /= 10;
    if (temp1 % 10 == rem)
        cout << a << '\n';
    else if (temp2 % 10 == rem)
        cout << b << '\n';
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
