#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string str;
    cin>>str;
    string result=" ";
    for(auto it= str.begin(); it!=str.end();it++)
    {
        if((*it=='.'))
        {
            result+='0';
        }
        else if ((*it=='-')&&(*(it+1)=='.'))
        {
            result+='1';
            it++;
        }
        else if((*it=='-')&&(*(it+1)=='-'))
        {
            result+='2';
            it++;
        }
    }
    cout<<result<<'\n';
    return 0;
}
