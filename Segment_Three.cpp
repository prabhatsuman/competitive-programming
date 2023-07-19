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
    int n;
    cin >> n;
    vi v(n);
    read(v);
    for (int i = 0; i < n; i++)
    {
        v[i] %= 3;
    }
   
    vector<vector<int>> temp(9, vector<int>(3, 0));
    temp[0] = {0, 0, 0};
    temp[1] = {0, 1, 2};
    temp[2] = {0, 2, 1};
    temp[3] = {1, 0, 2};
    temp[4] = {1, 1, 1};
    temp[5] = {1, 2, 0};
    temp[6] = {2, 0, 1};
    temp[7] = {2, 1, 0};
    temp[8] = {2, 2, 2};

    int ans = 1e9;
    for (int i = 0; i < 9; i++)
    {
        int count = 0;
        for (int j = 0; j < 3; j++)
        {
           if(temp[i][j]!=v[j])
           {
                if(temp[i][j]>v[j])
                {
                    count+=temp[i][j]-v[j];
                }
                else
                {
                    count+=3-v[j]+temp[i][j];
                }
           }
        }
        // cout<<i<<" ";
        // cout<<"count: "<<count<<nline;
        int first=temp[i][1];
        int second=temp[i][2];
        for(int j=3;j<n;j++)
        {
            int third=(3-(first+second+v[j])%3)%3;
            // cout<<third<<nline;
            count+=third;
            first=second;
            second=(third+v[j])%3;
        }
        ans = min(ans, count);
       
    }
    cout << ans << nline;
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
