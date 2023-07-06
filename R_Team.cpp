#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int res=0;
    for(int i=0; i<n; i++)
    {
        int count=0;
        for (int j=0; j<3; j++)
        {
            if(arr[i][j]==1)
            {
                count++;
            }
        }
        if(count>1)
        {
            res++;
        }
    }
    cout<<res<<'\n';

    return 0;
}
