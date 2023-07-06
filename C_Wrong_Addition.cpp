#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll a, c;
    cin >> a >> c;
    string a1 = to_string(a);
    string c1 = to_string(c);
    string res = "";
    int flag = 0;
    auto it1 = a1.rbegin();
    if (a1.length() > c1.length())
        cout << "-1" << '\n';
    else
    {

        for (auto it = c1.rbegin(); it != c1.rend(); it++)
        {

            if ((*it - '0') - (*it1 - '0') >= 0)
            {
                if (it1 != a1.rend())
                {
                    int temp = (*it - '0') - (*it1 - '0');

                    
                    res += to_string(temp);
                    it1++;
                }
                else
                {
                    int temp = *it-'0';
                    
                    res += to_string(temp);
                }
            }
            else
            {

                if (*(++it) == '1')
                {

                    int temp = (10 + (*(--it) - '0') - (*it1 - '0'));

                    res += to_string(temp);
                    it++;

                    it1++;
                }
                else
                {
                    flag = 1;
                    cout << "-1" << '\n';
                    break;
                }
            }
        }
        if (flag == 0)
        {
            if (it1 != a1.rend())
                cout << "-1" << endl;
            else
            {
                while(res.back()=='0')
                {
                    res.pop_back();
                }
                reverse(res.begin(), res.end());
                cout << res << endl;
            }
        }
    }
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
