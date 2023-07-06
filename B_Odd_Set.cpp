#include <bits/stdc++.h>
using namespace std;
void is_odd(int *x, int * ct)
{
    
    if (*x % 2 !=0)
    {
        ++*ct;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int count = 0;

        cin >> n;
        int arr[2 * n];
        for (int i = 0; i < (2 * n); i++)
        {

            cin >> arr[i];
        }

        for (int k = 0; k < 2 * n; k ++)
        {
            is_odd(arr + k, &count);
        }
        if (count == n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}