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
    int min_e = arr[0];
    int max_diff = 0;
   

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= min_e && (*(max_element(arr + i + 1, arr + n)) - arr[i])>max_diff && i<n-1)
        {
            

            min_e = arr[i];
            max_diff = *(max_element(arr + i + 1, arr + n)) - arr[i];
        }
    }
    
    cout << max_diff << '\n';

    return 0;
}
