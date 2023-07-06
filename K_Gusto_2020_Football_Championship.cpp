#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> team;
    int g1 = 0, g2 = 0;
    while (n--)
    {
        string str;
        cin >> str;
        team.push_back(str);
    }
    int len = team.size();
    string t1 = team[0];
    string t2;
    for (int i = 0; i < len; i++)
    {
        if (team[i] == t1)
        {
            g1++;
        }
        else
        {
            t2 = team[i];
            g2++;
        }
    }
    if (g1 > g2)
    {
        cout << t1 << endl;
    }
    else
    {
        cout << t2 << endl;
    }

    return 0;
}
