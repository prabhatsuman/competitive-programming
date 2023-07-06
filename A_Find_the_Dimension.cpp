#include <bits/stdc++.h>
using namespace std;
int main()
{
    int area;
    cin >> area;
    int l, h, L, H;
    int min = area;
    for (int i = 1; i <= area; i++)
    {
        if (area % i == 0)
        {
            h = area / i;
            l = i;
            if ((l <= h) && (h - l) < min)
            {
                min = (h - l);
                L = l;
                H = h;
            }
        }
    }
    cout << L << " " << H << endl;
    return 0;
}
