#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ct(vector<ll> v, ll N)
{
    ll count = 0;
    vector<ll> v1;
    vector<ll> v2;
    v1 = v;
    while (1)
    {
        for (ll i = 0; i < N; i += 2)
        {
            v2.push_back(v1[i]);
        }
        for (ll j = 1; j < N; j += 2)
        {
            v2.push_back(v1[j]);
        }
        v1.clear();
        v1 = v2;
        v2.clear();
        count++;
        if (v1 == v)
        {

            break;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll N, K;
        cin >> N >> K;
        if (N % 2 == 0)
        {
            vector<ll> v1;
            vector<ll> v2;

            for (ll i = 1; i <= N; i++)
            {
                v1.push_back(i);
            }
            ll count = ct(v1,N);

            if (K % count != 0)
            {
                K = K % count;

                while (K--)
                {
                    for (ll i = 0; i < N; i += 2)
                    {
                        v2.push_back(v1[i]);
                    }
                    for (ll j = 1; j < N; j += 2)
                    {
                        v2.push_back(v1[j]);
                    }
                    v1.clear();
                    v1 = v2;
                    v2.clear();
                }
            }

            for (ll i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
