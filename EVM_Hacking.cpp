#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, p, q, r;
        cin >> a >> b >> c >> p >> q >> r;
        int half = (p+q+r)/2;
        if(p+b+c>half or q+a+c>half or r+a+b>half) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
