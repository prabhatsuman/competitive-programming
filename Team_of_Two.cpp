#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
void seive();

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> temp;
        for (int j = 0; j < x; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }
    // int c = 15;
    bool f = false;

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            set<int> s;
            for (int l = 0; l < v[i].size(); l++)
            {
                s.insert(v[i][l]);
            }

            for (int k = 0; k < v[j].size(); k++)
            {
                s.insert(v[j][k]);
            }
            if (s.size() == 5)
            {
                f = true;
                break;
            }
        }
        if (f)
            break;
    }
    if (f)
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    int res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}

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