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
    set<string> s1, s2, s3;

    for (int j = 0; j < n; j++)
    {
        string temp;
        cin >> temp;
        s1.insert(temp);
    }
    for (int j = 0; j < n; j++)
    {
        string temp;
        cin >> temp;
        s2.insert(temp);
    }
    for (int j = 0; j < n; j++)
    {
        string temp;
        cin >> temp;
        s3.insert(temp);
    }
    int a = 0, b = 0, c = 0;
    for (auto &e : s1)
    {
        if (((s2.find(e) != s2.end()) && (s3.find(e) == s3.end()))|| ((s3.find(e) != s3.end()) &&(s2.find(e) == s2.end())))
            a++;
        else if (s2.find(e) == s2.end() && s3.find(e) == s3.end())
            a += 3;
    }
    cout<<a<<" ";
    for (auto &e : s2)
    {
        if (((s1.find(e) != s1.end()) && (s3.find(e) == s3.end()))|| ((s3.find(e) != s3.end()) &&(s1.find(e) == s1.end())))
            b++;
        else if (s1.find(e) == s1.end() && s3.find(e) == s3.end())
            b += 3;
    }
    cout<<b<<" ";
    for (auto &e : s3)
    {
        if (((s2.find(e) != s2.end()) && (s1.find(e) == s1.end()))|| ((s1.find(e) != s1.end()) &&(s2.find(e) == s2.end())))
            c++;
        else if (s2.find(e) == s2.end() && s1.find(e) == s1.end())
            c += 3;
    }
    cout<<c<<" ";
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