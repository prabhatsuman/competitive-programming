#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    int res=INT_MIN;
    int a,b;
    int i=0;
    
    while (n--)
    {
        cin>>a>>b;
        i-=a;
        i+=b;
        if(i>=res)
        {
            res=i;
        }
        
    }
    cout<<res;
     
    return 0;
}
