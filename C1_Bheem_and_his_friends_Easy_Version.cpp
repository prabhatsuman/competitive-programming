#include <bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    lli arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    lli ic = 0;

    lli m = 0;
    for (int i = 0; i < n; i++)
    {

        lli count = 0;
        for (int j = 1; j * j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                if (arr[i] / j == j)
                {
                    count++;
                }
                else
                {
                    count += 2;
                }
            }
        }
        if (ic < count)
        {
            m = i;
            ic = count;
        }
    }

    cout << m + 1 << '\n';
    return 0;
}
