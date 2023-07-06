#include <bits/stdc++.h>
using namespace std;
int main()
{
    string num[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= 9; i++)
    {
        cout<<num[i-1]<<endl;
        if(i==b)
        {
            break;
        }
    }
    for(int k=10;k<=b;k++)
    {
        if(k%2==0)
        {
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
        }
    }
    
    return 0;
}
