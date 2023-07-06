#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    int count = m.size();
    int k = 1;
    for (int i = 0; i < count; i++)
    {
        cout << count << " ";
        k++;
    }
    while (k <= n)
    {

        count++;
        cout << count << " ";
        k++;
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
