#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> m;
        int combo = 3;
        while (combo--)
        {
            ll a, b;
            cin>>a>>b;
            ll sum = a + b;

            m.push_back(sum);
        }
        sort(m.begin(), m.end(), greater<ll>());
        
        cout<<m[0]<<'\n';
    }

    return 0;
}
