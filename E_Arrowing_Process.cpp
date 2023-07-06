#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<string>v;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    ll count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(v[i][j]=='v' && v[i+1][j]=='^')
            {
                count++;
                char temp=v[i][j];
                v[i][j]=v[i+1][j];
                v[i+1][j]=temp;
            }
            else if(v[i][j]=='>' && v[i][j+1]=='<')
            {
                count++;
                char temp=v[i][j];
                v[i][j]=v[i][j+1];
                v[i][j+1]=temp;
            }
        }

    }
    cout<<count<<'\n';
    return 0;
}
