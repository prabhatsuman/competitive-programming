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
isRegularSequence(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            ct1++;
        else
            ct2++;
    }
    if (ct1 != ct2)
    {
        print(-1);
        return;
    }

    string temp = s;
    reverse(all(temp));
    if (isRegularSequence(s) || isRegularSequence(temp))
    {
        print(1);
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << nline;
        return;
    }
    stack<pair<char, int>> st;
    vector<bool> vis(n, false);
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push({s[i], i});
        }
        else
        {
            if (st.empty())
            {
                continue;
            }
            else
            {
                vis[i] = true;
                vis[st.top().second] = true;
                color[i] = 1;
                color[st.top().second] = 1;
                st.pop();
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color[i] = 2;
        }
    }
    print(2);
    printv(color);
    cout << nline;
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
