#include<bits/stdc++.h>
#define ll long long
#define  A (double)0.143
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double ans= pow(A*n,n);
        cout<<round(ans)<<'\n';
    }
    
    return 0;
}
