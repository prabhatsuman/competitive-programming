#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int X,Y,Z;
       cin>>X>>Y>>Z;
       if(X>=Y)
       {
           cout<<"PIZZA\n";
       }
       else
       {
           if(X>=Z)
           {
               cout<<"BURGER\n";
           }
           else
           {
               cout<<"NOTHING\n";
           }
       }
   } 
    return 0;
}
