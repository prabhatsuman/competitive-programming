#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int temp = n;
    int len = 0;
    int div, rem;
    int ans;
    while (n > 0)
    {
        len++;
        n = n / 10;
    }
    n = temp;
    if (len == 1)
    {
        ans = 1;
    }
    if (len > 1)
    {
        div = pow(10, len - 1);
        if (n % div != 0)
        {
            rem = n % div;
            ans = div - rem;
        }
        else
        {
            ans = div;
        }
    }
    cout << ans << endl;

    return 0;
}
