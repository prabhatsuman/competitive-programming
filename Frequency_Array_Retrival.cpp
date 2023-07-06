#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
void sieve();
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second < i.first)
        {
            cout << -1 << nline;
            return;
        }
    }
    vector<int> ans;
    map<int, int> freq;
    map<int, int> val;
    int value = 1;
    for (int i = 0; i < n; i++)
    {
        if (freq.find(v[i]) == freq.end())
        {
            freq[v[i]] = 1;
            val[v[i]] = value;
            ans.push_back(value);
            value++;
        }
        else if (freq[v[i]] < v[i])
        {
            freq[v[i]]++;
            ans.push_back(val[v[i]]);
        }
        else
        {
            freq[v[i]] = 1;
            val[v[i]] = value;
            ans.push_back(value);
            value++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<nline;
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