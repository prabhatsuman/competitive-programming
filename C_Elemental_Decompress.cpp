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
    vector<pair<int, int>> p;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        p.push_back({v[i], i});

        m[v[i]]++;
    }

    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b)
         {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first; });

    // bool flag = true;
    bool flag1 = false;
    for (auto i : m)
    {
        if (i.second > 2)
        {
            flag1 = true;
            break;
        }
    }
    if (flag1)
    {
        cout << "NO" << nline;
        return;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (m[i] == 0)
        {
            pq.push(i);
        }
    }
    vector<int> a(n);
    vector<int> b(n);
    vector<bool> vis(n + 1, false);
    for (int i = n - 1; i >= 0; i--)
    {
        if (vis[p[i].first])
            continue;
        vis[p[i].first] = true;

        if (m[p[i].first] == 2)
        {
            if (pq.empty())
            {
                cout << "NO" << nline;
                return;
            }
            if (pq.top() > p[i].first)
            {

                cout << "NO" << nline;
                return;
            }

            a[p[i].second] = p[i].first;
            b[p[i].second] = pq.top();
            a[p[i - 1].second] = pq.top();
            b[p[i - 1].second] = p[i].first;
            pq.pop();
        }
        if (m[p[i].first] == 1)
        {
            a[p[i].second] = p[i].first;
            b[p[i].second] = p[i].first;
        }
    }

    cout << "YES" << nline;
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << nline;
    for (auto i : b)
    {
        cout << i << " ";
    }
    cout << nline;
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