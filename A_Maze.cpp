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
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
#define print2d(v) for (int i = 0; i < v.size(); i++) { for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " "; cout << nline; }
#define printp(v) for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << nline;
#define printm(m) for (auto it = m.begin(); it != m.end(); it++) cout << it->first << " " << it->second << nline;
#define prints(s) for (auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
//find path of dfs
int n,m,k;

void dfs(int i,int j,vector<string> &v,vector<vector<bool>> &vis)
{
    if(i<0 || j<0 || i>=n || j>=m )
    {
        return;
    }
    if(v[i][j]=='#')
    {
        
        return;
    }
   
    if(vis[i][j])
    {
        return;
    }
    vis[i][j]=true;
    dfs(i+1,j,v,vis);
    dfs(i-1,j,v,vis);
    dfs(i,j+1,v,vis);
    dfs(i,j-1,v,vis);
    if(k!=0)
    {
        v[i][j]='X';
        k--;
    }  

  

}
void solve()
{

    cin>>n>>m>>k;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int row=0,col=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.')
            {
                row=i;
                col=j;
                flag=true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    dfs(row,col,v,vis);
   
    
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<nline;
    }

    

}

int main()
{
    godspeed;
    ll t=1;
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

