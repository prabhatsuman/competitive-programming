#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    string s;
    cin >> s;
    int n=s.size();
    string c="";
    set<char> a;
    for(int i=0; i<n; i++)
    {
        if(a.find(s[i])==a.end())
        {
            c+=s[i];
            a.insert(s[i]);
        }
    }
    //cout<<c.size()<<nline;
    //cout<<c<<nline;
   
    bool f=true;
    int ab = c.size();
    for(int i=0; i<n; i++)
    {
    
        //cout<<c[i%c.size()]<<" "<<s[i]<<nline;
       
      //  cout<<s[i]<<nline;
        if(s[i]!=c[i%ab])
        {
            //cout<<1<<nline;
            f=false;
            break;
        }
    }
    if(f)
    {
        cout<<"YES"<<nline;
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
