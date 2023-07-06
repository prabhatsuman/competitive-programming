#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int max = floor(n / 2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int y = arr[0];
    for (int i = 1; i <= max; i++)
    {
        cout << arr[i] << " " << y << '\n';
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
