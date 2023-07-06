#include <bits/stdc++.h>
using namespace std;
int main()
{
    // a= size of video per sec
    // b= download speed per sec
    // c= time of video
    int a, b, c;
    cin >> a >> b >> c;
    int total_data;
    int data_avail;
    int req;
    int t;
    total_data=a*c;
    data_avail=b*c;
    req=total_data-data_avail;
    t=req/b ;
    if(req%b!=0)
    {
        t++;
    }
    cout<<t<<endl;
    return 0;
}
