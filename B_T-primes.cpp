#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 10e6 + 1;
const long long N = 10e12 + 1;
unordered_set<ll> squares;
vector<bool> isPrime(M, 1);
void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= M; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= M; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
void PrimeSq()
{
    for (ll i = 1; i <= M; i++)
    {
        if (isPrime[i])
        {
            squares.insert(i * i);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (squares.find(v[i])!=squares.end())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    PrimeSq();
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
