#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define lli long long int
using namespace std;
int main()
{
    int t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli fact = 1;
        for (lli i = 1; i <= n; i++)
        {
            fact = (fact * i) % M;
        }
        cout << fact << '\n';
    }

    return 0;
}
