#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    int bal[5] = {100, 20, 10, 5, 1};
    for (int i = 0; i < 5; i++)
    {
        count += n / bal[i];
        if (n % bal[i] == 0)
        {
            break;
        }
        else
        {
            n = n % bal[i];
        }
    }
    cout << count << endl;
    return 0;
}
