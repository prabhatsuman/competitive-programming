#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int i=0,j=0;
    int m=INT_MIN;
    while(j<k)
    {
        m=max(m,v[j]);
        j++;
    }
    cout<<m<<endl;
    while(j<n)
    {
        if(v[i]==m)
        {
            m=INT_MIN;
            for(int k=i+1;k<=j;k++)
            {
                m=max(m,v[k]);
            }
            cout<<m<<endl;
            i++;
            j++;
        }
        else
        {
            m=max(m,v[j]);
            cout<<m<<endl;
            i++;
            j++;
        }
   

    }


    return 0;
}