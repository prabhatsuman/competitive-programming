#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << "YES" << '\n';
        }
        else
        {

            int lo = 0;
            int hi = n - 1;
            int count = 0;
            while (lo < hi)
            {
                if (s[lo] != s[hi])
                {
                    count++;
                }
                lo++;
                hi--;
            }
            if (count <= k)
            {

                if (n % 2 == 0)
                {
                    int temp = k - count;
                    if (temp % 2 == 0)
                    {
                        cout << "YES" << '\n';
                    }
                    else
                    {
                        cout << "NO" << '\n';
                    }
                }
                else
                {
                    cout << "YES" << '\n';
                }
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
