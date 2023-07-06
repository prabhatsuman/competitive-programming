#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll count = 0;
    for (ll i = 19;; i += 9)
    {
        ll temp = i;
        ll sum = 0;
        while (temp > 0)
        {
            ll rem = temp % 10;
            sum += rem;
            temp /= 10;
        }
        if (sum == 10)
        {
            count++;
        }
        if (count == n)
        {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
