#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            c1++;
        else
            c2++;
    }
    int diff = abs(c1 - c2);
    char temp;
    int m = INT_MIN;
    if (c1 > c2)
    {
        m = c1;
        temp = '0';
    }
    else if(c1<c2)
    {
        m = c2;
        temp = '1';
    }
    else
    {
        cout<<"YES"<<nline;
        cout<<1<<" "<<n<<nline;
        return;
    }

    if (diff & 1)
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
        int i1 = -1, j1 = -1;
        
        int count = m + diff / 2;
        int c = 0;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == temp)
            {
                count--;
                c++;
                if (c < 2)
                    i1 = i;
            }
            else
            {
                count = m + diff / 2;
                i1 = -1;
                c=0;
            }
            if (count == m)
            {
                j1 = i;
                break;
            }
        }
        cout << i1+1 << " " << j1+1 << nline;
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
