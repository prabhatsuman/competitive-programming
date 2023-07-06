#include <bits/stdc++.h>
#define ll long long
#define MAX (int)(2 * 10e5)
using namespace std;
int prefix[MAX+1][31];
void precompute()
{
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            if (i & (1 << j))
            {
                prefix[i][j] = 1;
            }
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int total=r-l+1;
    int ans=(int)10e5;
    
    for (int i = 0; i <= 30; i++)
    {
        int temp=prefix[r][i]-prefix[l-1][i];
        ans=min(ans,total-temp);

    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
