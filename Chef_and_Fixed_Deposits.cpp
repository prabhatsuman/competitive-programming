#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N,X;
       cin>>N>>X;
       vector<int> v;

       for(int i=0; i<N;i++)
       {
           int temp;
           cin>>temp;
           v.push_back(temp);
       }
       sort(v.begin(),v.end(),greater<int>());
       ll sum=0;
       ll count=0;
       int a=0;
       for(int i=0; i<N; i++)
       {
           sum+=v[i];
           count++;
           if(sum>=X)
           {
               a=1;
               cout<<count<<'\n';
               break;
           }
       }
       if(a==0)
       {
          cout<<"-1"<<'\n'; 
       }
   } 
    return 0;
}
