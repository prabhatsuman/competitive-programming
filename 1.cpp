#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        mp[x] += 1;
        mp[y + 1] += -1;
    }
    int ans = 0;
    int sum = 0;
    for (auto it : mp)
    {
        sum += it.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}