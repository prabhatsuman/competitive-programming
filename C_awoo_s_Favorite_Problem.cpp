/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (n == 1)
    {
        if (a == b)
        {
            yes;
            return;
        }
        else
        {
            no;
            return;
        }
    }
    if (a == b)
    {
        yes;
        return;
    }
    deque<int> pos_a, pos_b, pos_c;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'b')
        {
            pos_b.push_back(i);
        }
        else if (a[i] == 'c')
        {
            pos_c.push_back(i);
        }
        else
        {
            pos_a.push_back(i);
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {

            if (b[i] == 'a')
            {
                pos_a.pop_front();
            }
            else if (b[i] == 'b')
            {

                // cout<<i<<" "<<pos_b.front()<<nline;

                pos_b.pop_front();
                // cout << pos_b.front() << nline;
            }
            else
            {
                pos_c.pop_front();
            }
            continue;
        }
        if (b[i] == 'b')
        {

            // if (pos_b.empty())
            // {
            //     flag = false;
            //     break;
            // }
            if (pos_b.empty())
            {
                flag = false;
                break;
            }

            int t1 = pos_b.front();
            int t2 = n + 1;
            if (!pos_c.empty())
            {
                t2 = pos_c.front();
            }

            if (t1 > t2 || i>t1)
            {
                // cout<<t1<<" "<<t2<<nline;
                flag = false;
                break;
            }
            else
            {
                // cout << i << " " << t1 << endl;
                swap(a[i], a[t1]);
                pos_b.pop_front();
                pos_a.pop_front();
                pos_a.push_front(t1);
                // cout << i << " " << a << endl;
            }
            continue;
        }
        if (b[i] == 'c')
        {
            // if (pos_c.empty())
            // {
            //     flag = false;
            //     break;
            // }
            if (pos_c.empty())
            {
                flag = false;
                break;
            }
            int t1 = pos_c.front();
            int t2 = n + 1;
            if (!pos_a.empty())
            {
                t2 = pos_a.front();
            }
            // int t2 = pos_a.front();
            if (t1 > t2 || i>t1)
            {
                // cout << t1 << " " << t2 << nline;
                flag = false;
                break;
            }
            else
            {
                // cout<<t1<<" "<<t2<<nline;
                swap(a[i], a[t1]);
                pos_c.pop_front();
                pos_b.pop_front();
                pos_b.push_front(t1);

                // cout << i << " " << a << endl;
            }
            continue;
        }
    }
    // cout << a << nline;

    if (a != b)
    {
        flag = false;
    }
    if (flag)
    {
        yes;
    }
    else
    {
        no;
    }
}

int main()
{
    godspeed;
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
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
