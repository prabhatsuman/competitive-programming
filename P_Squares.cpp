#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll row = 0;
    ll col = 0;
    ll diff = 0;
    vector<ll> sides;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        sides.push_back(temp);
    }

    if (k > n)
    {
        cout << "-1" << '\n';
    }
    else
    {
        sort(sides.begin(), sides.end());
        diff = n - k;
        row = col = sides[diff];
        cout << row << " " << col << '\n';
    }

    return 0;
}
