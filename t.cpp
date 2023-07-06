#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(start, end, i) for(long long i=start; i<end; i++)
#define frr(start, end, i) for(long long i=start; i<=end; i++)
#define fre(container, element) for(auto &element : container)
#define nl "\n"
#define tocap &(~(1<<5))
#define tosmall |(1<<5)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
 
int main () {
    fastio
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        string str;
        cin >> n >> str;
        str += "W";
        ll a=0,b=0;
        bool flag = true;
        for (ll i=0; i<=n; i++) {
            if (str[i]=='W' && a+b==1) flag = false;
            if (str[i]=='W') {a=0;b=0;}
            if (str[i]=='R') a=1;
            if (str[i]=='B') b=1;
        }
        if (flag) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    return 0;
}