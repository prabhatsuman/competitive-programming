#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int t1,t2,r1,r2;
        cin>>t1>>t2>>r1>>r2;
        float T = pow(t1,2)/pow(t2,2);
        float R= pow(r1,3)/pow(r2,3);
        if (T==R)
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
