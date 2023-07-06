#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'r')
            a++;
        else if (s[i] == 'R')
            a--;
        else if (s[i] == 'g')
            b++;
        else if (s[i] == 'G')
            b--;
        else if (s[i] == 'b')
            c++;
        else if (s[i] == 'B')
            c--;
        //cout<<a<<" "<<b<< " "<<c<<"\n";

        if (a < 0 || b < 0 || c < 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
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
