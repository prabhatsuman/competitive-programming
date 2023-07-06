#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n,k;
       cin>>n>>k;
       int a[n][n];
         for(int i=0;i<n;i++)
         {
              for(int j=0;j<n;j++)
              {
                cin>>a[i][j];
              }
         }
         //rotate 180
            int b[n][n];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    b[i][j]=a[n-i-1][n-j-1];
                }
            }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=b[i][j])
                {
                    count++;
                }
            }
        }
        if(count/2==k)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(count/2>k)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            if(n&1)
            {
                cout<<"YES"<<endl;
                continue;
            }
            int t=k-count/2;
            if(t&1)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                cout<<"YES"<<endl;
                continue;
            }
        }


    }
    return 0;
}
