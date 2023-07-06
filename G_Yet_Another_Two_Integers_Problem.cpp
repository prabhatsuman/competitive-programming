#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int count = 0;
        int a, b;
        int rem;
        cin >> a >> b;
        if (b > a)
        {
            rem = b - a;
            if ((10 * (rem / 10)) + a == b)
            {
                count = (rem / 10);
            }
            else
            {
                count = (rem / 10) + 1;
            }
        }
        else if (a > b)
        {
            rem = a - b;
            if (a - (10 * (rem / 10)) == b)
            {
                count = (rem / 10);
            }
            else
            {
                count = (rem / 10) + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}


