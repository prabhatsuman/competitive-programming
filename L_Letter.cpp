#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    char arr[51][51];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i_min = n;
    int i_max = -1;
    int j_min = m;
    int j_max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '*')

            {
                if (i < i_min)
                {
                    i_min = i;
                }
                if (j < j_min)
                {
                    j_min = j;
                }
                if (j > j_max)
                {
                    j_max = j;
                }
                if (i > i_max)
                {
                    i_max = i;
                }
            }
        }
    }
    for (int i = i_min; i <= i_max; i++)
    {
        for (int j = j_min; j <= j_max; j++)
        {
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    return 0;
}
