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
#define read(x)       \
    for (auto &c : x) \
        cin >> c;
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
    vi v(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int z1 = -1, z2 = -1;
    int cnt2 = 0;
    int cntneg = 0;
    int firstneg = -1;
    int lastneg = -1;
    // cout<<v[n+1]<<nline;
    vector<pair<int, pair<int, int>>> ans;
    for (int i = 0; i <= n + 1; i++)
    {
        if (v[i] == 0)
        {
            if (z1 == -1)
            {
                z1 = i;
            }
            else
            {
                z2 = i;
                if (cntneg % 2 == 0)
                {
                    ans.pb({cnt2, {z1, (n + 1) - z2}});
                }
                else
                {
                    int t1 = 0, t2 = 0;

                    for (int i = z1; i <= firstneg; i++)
                    {
                        if (abs(v[i]) == 2)
                        {
                            t1++;
                        }
                    }
                    for (int i = lastneg; i <= z2; i++)
                    {
                        if (abs(v[i]) == 2)
                        {
                            t2++;
                        }
                    }
                    if (t1 > t2)
                    {
                        ans.pb({cnt2 - t2, {z1, (n + 1) - lastneg}});
                    }
                    else
                    {
                        ans.pb({cnt2 - t1, {firstneg, (n + 1) - z2}});
                    }
                }
                z1 = i;
                z2 = -1;
                cnt2 = 0;
                cntneg = 0;
                firstneg = -1;
                lastneg = -1;
            }
        }
        else
        {
            if (abs(v[i]) == 2)
                cnt2++;
            if (v[i] < 0)
            {
                cntneg++;
                if (firstneg == -1)
                {
                    firstneg = i;
                    lastneg = i;
                }
                else
                {
                    lastneg = i;
                }
            }
        }
    }

    sort(ans.rbegin(), ans.rend());
    // cout << ans.size() << nline;
    // for (auto it : ans)
    // {
    //     cout << it.first << " " << it.second.first << " " << it.second.second << nline;
    // }
    cout << ans[0].second.first << " " << ans[0].second.second << nline;
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
