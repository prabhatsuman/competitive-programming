#include<bits/stdc++.h>
using namespace std;
int winner(int p, int t)
{
   int a1=(3*p)/10;
   int a2= p-(p/250)*t;
   return max(a1,a2); 
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int w= winner(a,c);
    int g= winner(b,d);
    if (w>g)
    {
        cout<<"Wacky"<<endl;
    }
    else if(w<g)
    {
        cout<<"Gami"<<endl;
    }
    else
    {
       cout<<"Tie"<<endl;  
    }
    return 0;
}
