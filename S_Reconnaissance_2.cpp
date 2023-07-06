#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = abs(arr[1] - arr[0]);
    int res1, res2;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && abs(arr[i + 1] - arr[i]) <= min)
        {
            min = abs(arr[i + 1] - arr[i]);
            res1 = i;
            res2 = i + 1;
        }
        else if (i == n - 1 && abs(arr[0] - arr[i]) <= min)
        {
            min = abs(arr[0] - arr[i]);
            res1 = i;
            res2 = 0;
        }
    }
    cout << res1 + 1 << " " << res2 + 1 << '\n';

    return 0;
}
