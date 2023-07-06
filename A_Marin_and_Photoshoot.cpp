#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '0' && s[i + 1] == '0')
        {
            count += 2;
        }
        if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0')
        {
            count+=1;
        }
    }
    cout << count << nline;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
