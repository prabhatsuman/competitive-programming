#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MAX = 1000000000;
vector<int> Lcm;
void precompute()
{
    int temp = 2;
    Lcm.push_back(temp);

    int i = 3;

    while (temp <= MAX)
    {
        temp = lcm(temp, i);
        i++;
        Lcm.push_back(temp);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < Lcm.size(); i++)
    {
        if (v[i] % Lcm[i] == 0 && i < n)
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
