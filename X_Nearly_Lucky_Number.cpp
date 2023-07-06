#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    ll temp = m['4'] + m['7'];
    if (temp == 0)
    {
        cout << "NO";
    }
    else
    {

        int flag = 0;
        ll rem = 0;
        while (temp > 0)
        {
            rem = temp % 10;
            
            if (rem != 4 && rem != 7)
            {

                flag = 1;
                break;
            }
            temp /= 10;
        }

        if (flag == 1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }

    return 0;
}
