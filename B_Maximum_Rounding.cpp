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
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
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
    string s;
    cin >> s;
    int n = s.length();
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '5')
        {
            // s[i]='0';
            ind = i;
            break;
        }
    }
    if (ind == 0)
    {
        string res = "1";
        for (int i = 0; i < n; i++)
        {
            res += '0';
        }
        cout << res << nline;
    }
    else
    {
        if (ind == -1)
        {
            cout << s << nline;
        }
        else
        {
            string res = "";
            for (int i = 0; i < ind - 1; i++)
            {
                res += s[i];
            }
            // cout<<res<<nline;

            if (s[ind - 1] != '4')
                res += ++s[ind - 1];
            else
            {
                res += '0';
            }

            int j = ind - 2;
            bool flag = false;
            if (s[j + 1] == '4')
            {

                while (j >= 0 && s[j] == '4')
                {
                    flag = true;
                    res[j] = '0';
                    j--;
                }
            }

            if (flag)
            {

                if (j == -1)
                {
                    res = "1" + res;
                }
                else
                {
                    res[j]++;
                }
            }
            // cout<<j<<nline;
            // cout<<ind<<nline;
            // cout<<n
            //   res+='0';
            for (int j = ind; j < n; j++)
            {
                res += '0';
            }

            cout << res << nline;
        }
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
