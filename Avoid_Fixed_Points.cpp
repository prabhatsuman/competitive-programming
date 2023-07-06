#include <bits/stdc++.h>
#define ll long long
#define MAX (int)10e5 + 1
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v;
    int count = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        if (j != temp)
        {
            v.push_back(temp);
            j++;
        }
        else
        {
            count++;
            v.push_back(MAX);
            j++;
            v.push_back(temp);
            j++;
        }
    }

    cout << count << '\n';
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
