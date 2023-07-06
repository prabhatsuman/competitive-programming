#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ld arr[n];
        ld sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        ld m = *max_element(arr, arr + n);
        sum = sum - m;

        ld res = sum / ((ld)(n - 1)) + m;
        cout << fixed << res << setprecision(6) << '\n';
    }
    return 0;
}
