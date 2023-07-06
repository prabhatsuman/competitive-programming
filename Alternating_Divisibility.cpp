#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int i = 0;
    int temp = n;
    if (n % 2 == 0)
    {

        while (i < temp - 1)
        {

            cout << n << " ";
            cout << n * 2 << " ";
            i++;
            i++;

            n--;
        }
    }
    else
    {
        while (i < temp - 2)
        {

            cout << n << " ";
            cout << n * 2 << " ";
            i++;
            i++;

            n--;
        }
        cout << n << " ";
    }

    cout << '\n';
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
