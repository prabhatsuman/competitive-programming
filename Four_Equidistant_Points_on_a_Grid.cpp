#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n%2==1)
    {
        cout<<-1<<'\n';
        return;
    }
    cout << 0 << " " << n / 2 << '\n';
    cout << n / 2 << " " << 0 << '\n';
    cout << 0 << " " << -(n / 2) << '\n';
    cout << -(n / 2) << " " << 0 << '\n';

    return 0;
}
