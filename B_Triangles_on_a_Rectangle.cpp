#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll w, h;
    cin >> w >> h;
    int w1, w2, h1, h2;
    cin >> w1;
    vector<int> W1(w1);
    for (int i = 0; i < w1; i++)
    {
        cin >> W1[i];
    }
    cin >> w2;
    vector<int> W2(w2);
    for (int i = 0; i < w2; i++)
    {
        cin >> W2[i];
    }
    cin >> h1;
    vector<int> H1(h1);
    for (int i = 0; i < h1; i++)
    {
        cin >> H1[i];
    }
    cin >> h2;
    vector<int> H2(h2);
    for (int i = 0; i < h2; i++)
    {
        cin >> H2[i];
    }
    ll res = 1;
    ll res1 = 1, res2 = 1, res3 = 1, res4 = 1;
    res1 = (W1.back() - W1.front()) * h;
    res2 = (W2.back() - W2.front()) * h;
    res3 = (H1.back() - H1.front()) * w;
    res4 = (H2.back() - H2.front()) * w;
    res = max(max(max(res1, res2), res3), res4);
    cout << res << '\n';
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
