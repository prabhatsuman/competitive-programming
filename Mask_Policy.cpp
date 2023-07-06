#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int N, A;
        cin >> N >> A;
        int res = min(A, N - A);
        cout << res << '\n';
    }
    return 0;
}
