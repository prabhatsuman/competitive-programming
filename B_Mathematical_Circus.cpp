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
    int n, k;
    cin >> n >> k;
    int count = n / 4;
    
    vector<int> odd;
    vector<int> not4;
    vector<int> four;
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i += 2)
    {
        odd.push_back(i);
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (i % 4 != 0)
            not4.push_back(i);
        else
            four.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < four.size(); i++)
    {
        res.push_back({odd[j], four[i]});
        j++;
    }
    bool f = true;
    if (k % 2 == 0)
    {
        for (auto &e : not4)
        {
            if ((e + k) % 4 != 0)
            {
                f = false;
                break;
            }

            else
            {
                res.push_back({e, odd[j]});
                j++;
            }
        }
    }
    else
    {
        for(auto &e: not4)
        {
            res.push_back({odd[j],e});
            j++;
        }
    }
    sort(res.begin(),res.end());
    if(f)
    {
        cout<<"YES"<<nline;
        for(auto &e: res)
        {
            cout<<e.first<<" "<<e.second<<nline;
        }
    }
    else
    {
        cout<<"NO"<<nline;
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
