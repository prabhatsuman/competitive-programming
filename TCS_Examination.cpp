#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int Dragon[3];
        int Sloth[3];
        
        for(int i=0;i<3;i++)
        {
            cin>>Dragon[i];
        }
        for(int i=0; i<3; i++)
        {
            cin>>Sloth[i];
        }
        int sum1=Dragon[0]+Dragon[1]+Dragon[2];
        int sum2=Sloth[0]+Sloth[1]+Sloth[2];
        if(sum1>sum2)
        {
            cout<<"DRAGON"<<'\n';
        }
        else if(sum1<sum2)
        {
            cout<<"SLOTH"<<'\n';
        }
        else
        {
            if(Dragon[0]>Sloth[0])
            {
                cout<<"DRAGON"<<'\n';
            }
            else if(Dragon[0]<Sloth[0])
            {
               cout<<"SLOTH"<<'\n'; 
            }
            else if(Dragon[0]==Sloth[0])
            {
                if(Dragon[1]>Sloth[1])
                {
                    cout<<"DRAGON"<<'\n';
                }
                else if(Dragon[1]<Sloth[1])
                {
                    cout<<"SLOTH"<<'\n';
                }
                else if(Dragon[1]==Sloth[1])
                {
                    cout<<"TIE"<<'\n';
                }
            }
        }
    }
    return 0;
}
