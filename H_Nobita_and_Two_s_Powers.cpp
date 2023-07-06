#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    if (__popcount(n) > k || k > n)
    {
        cout << "NO"
             << "\n";
    }
    else
    {
        cout << "YES" << '\n';
        int i = 0;
        multiset<int> res;
        while (n)
        {

            if (n & 1)
            {
                int temp = pow(2, i);
                res.insert(temp);
            }
            n >>= 1;
            i++;
        }
        while (res.size() != k)
        {
            auto it = --res.end();
            int temp = *it;
            res.erase(it);
            res.insert(temp / 2);
            res.insert(temp / 2);
        }
        for (auto &values : res)
        {
            cout << values << " ";
        }
    }

    return 0;
}
