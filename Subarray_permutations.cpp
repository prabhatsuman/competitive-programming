#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int flag = 0;
        vector<int> res;
        if (n == k)
        {
            flag = 1;
            for (int i = 1; i <= n; i++)
            {
                res.push_back(i);
            }
        }
        else if (k < 2)
        {
            cout << "-1"<<'\n';
        }
        else
        {
            flag = 1;
            for (int i = 1; i < k; i++)
            {
                res.push_back(i);
            }
            for (int j = n; j >= k; j--)
            {
                res.push_back(j);
            }
        }
        if (flag == 1)
        {
            for (auto &r : res)
            {
                cout << r << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}
