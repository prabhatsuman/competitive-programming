#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int r, c, a, b;

        cin >> r >> c >> a >> b;

        char v[r][c];
        // cout<<v.size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> v[i][j];
            }
        }

        // cout << v.size()<<endl;

        int flag = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v[i][j] == 'B')
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            if (v[a - 1][b - 1] == 'B')
            {
                cout << 0 << '\n';
            }
            else
            {
                bool f1 = false, f2 = false;
                for (int i = 0; i < c; i++)
                {
                    if (v[a - 1][i] == 'B')
                    {
                        f1 = true;
                        break;
                    }
                }
                for (int i = 0; i < r; i++)
                {
                    if (v[i][b - 1] == 'B')
                    {
                        
                        f2 = true;
                        break;
                    }
                }
                if (f1 || f2)
                {
                    cout << 1 << '\n';
                }
                else
                {
                    cout << 2 << '\n';
                }
            }
        }
    }
    return 0;
}
