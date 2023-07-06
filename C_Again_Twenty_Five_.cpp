#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    double p = pow(5, n);

    long long last_digit = 0;
    while (count < 2)
    {
        last_digit = last_digit * 10 + ((long)p % 10);
        p = p / 10;
        count++;
    }
    cout << p << endl;
    cout << last_digit << endl;
    return 0;
}
