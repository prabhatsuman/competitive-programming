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
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<vector<int>> v;
    vector<int> index;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<int> temp;
        bool flag = false;
        for (int j = 0; j < a; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
            mp[x]++;
        }

        v.push_back(temp);
    }
    // print index
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (mp[v[i][j]] > 1)
            {
                index.push_back(i);
                break;
            }
        }
    }
    // //print index
    // for(int i=0;i<index.size();i++){
    //     cout<<index[i]<<" ";
    // }
    // cout<<nline;

    bool flag = false;
    for (int i = 0; i < index.size(); i++)
    {
        bool flag1 = false;
        for (int j = 0; j < v[index[i]].size(); j++)
        {
            if (mp[v[index[i]][j]] == 1)
            {
                flag1 = true;
                break;
            }
        }
        if (flag1 == false)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << nline;
    }
    else
    {
        cout << "NO" << nline;
    }
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
