#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        int b[n];
        int flag=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            if(b[i]-a[i]==x || b[i]-a[i]==y)
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
