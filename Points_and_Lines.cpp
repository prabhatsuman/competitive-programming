#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<ll> s1;
    set<ll> s2;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        s1.insert(temp1);
        s2.insert(temp2);
    }
    ll ct = 0;
    ct += s1.size();
    ct += s2.size();
    cout << ct << '\n';
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
