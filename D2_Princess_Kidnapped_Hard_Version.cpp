#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define Max 1000000
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<lli> v;

    ll fact=1;
    v.push_back(fact);

    for (ll i = 2; i <= Max; i++)
    {

       fact=(fact*i)%M;
       v.push_back(fact);
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        cout << v[n-1] << '\n';
    }

    return 0;
}
