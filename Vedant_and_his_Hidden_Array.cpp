#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, b;
        cin >> n >> b;
        if (n == 1)
        {
            if (b % 2 == 0)
            {
                cout << "Even" << '\n';
            }
            else
            {
                cout << "Odd" << '\n';
            }
        }
        else if (b % 2 != 0)

        {
            if (n % 2 == 0)
            {
                cout << "Even" << '\n';
            }
            else
            {
                cout << "Odd" << '\n';
            }
        }
        else
        {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}
