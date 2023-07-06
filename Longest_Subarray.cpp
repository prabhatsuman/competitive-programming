#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
void solve()
{
    int n;
    cin >> n;
    int v[n][32];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 32; j++)
        {
            v[i][j] = x % 2;
            x /= 2;
        }
    }
    bool flag = false;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            count += v[j][i];
        }
        if (count == 1)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << -1 << nline;
        return;
    }
    // //print v
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 32; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << nline;
    // }
    int m = -1;
    int dp1[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 1)
            {
                dp1[i] = j + 1;
                break;
            }
        }
    }
    int dp2[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[j][i] == 1)
            {
                dp2[i] = j + 1;
                break;
            }
        }
    }
    int dp[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        if (n + 1 - dp2[i] > dp1[i])
        {
            dp[i] = dp1[i];
        }
        else
        {
            dp[i] = dp2[i];
        }
    }
    // print dp1 and dp2
    //  for (int i = 0; i < 32; i++)
    //  {
    //      cout << dp1[i] << " ";
    //  }
    //  cout << nline;
    //  for (int i = 0; i < 32; i++)
    //  {
    //      cout << dp2[i] << " ";
    //  }
    //  cout << nline;
    // print dp
    // for (int i = 0; i < 32; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << nline;
    set<int> s;
    for (int i = 0; i < 32; i++)
    {
        if (dp[i] != 0)
            s.insert(dp[i]);
    }
    vector<int> ans;
    for(auto i:s){
        ans.push_back(i);
    }
    int ans1=ans[0]-1;
    int ans2=n-ans[ans.size()-1];
    int ans3=0;
    if(ans.size()!=1)
    {
        ans3=ans[ans.size()-1]-ans[ans.size()-2]-1;
    }
    cout<<max(ans1,max(ans2,ans3))<<nline;
    // cout << nline;
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
