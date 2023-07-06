#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum_of_digit(ll a)
{
    int sum = 0;
    int rem = 0;
    while (a > 0)
    {
        rem = a % 10;
        sum += rem;
        a = a / 10;
    }
    return sum;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a;
        cin >> a;
        if (__gcd(a, sum_of_digit(a)) > 1)
        {
            cout << a << '\n';
        }
        else
        {
            while (1)
            {
                a++;
                if (__gcd(a, sum_of_digit(a)) > 1)
                {
                    cout << a << '\n';
                    break;
                }
            }
           
        }
    }

    return 0;
}
