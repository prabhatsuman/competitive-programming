#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double n, m, a;
    cin >> n >> m >> a;
    ll a1 = ceill(n / a);
    ll a2 = ceill(m / a);
    cout << a1 * a2 << '\n';
    return 0;
}
