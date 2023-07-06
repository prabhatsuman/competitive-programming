#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int y=0, count=0;
        while(y<x)
        {
            y+=pow(2,count);
            count++;
        }
        count++;
        y+=pow(2,count);

        
        cout<<"0"<<" "<<y<< " "<<x<<'\n';
    }
    return 0;
}
