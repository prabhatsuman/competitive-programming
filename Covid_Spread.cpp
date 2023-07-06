#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long i;
        long long N, D;
        cin >> N >> D;
        long long infected = 1;
        if (D == 0)
        {
            cout << infected << endl;
        }
        else
        {
            for (i = 1; i <= 10; i++)
            {
                infected *= 2;
                if (infected >= N)
                {
                    cout << N << endl;
                    break;
                }
                else if (i == D)
                {
                    cout << infected << endl;
                    break;
                }
            }
            if (i > 10)
            {
                while (1)
                {
                    infected *= 3;
                    if (infected >= N)
                    {
                        cout << N << endl;
                        break;
                    }
                    else if (i == D)
                    {
                        cout << infected << endl;
                        break;
                    }
                    i++;
                }
            }
        }
    }

    return 0;
}
