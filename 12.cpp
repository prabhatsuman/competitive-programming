// BAKHTABAR
#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n)    for(ll i=j; i<n; i++)
#define rrep(i, n, j)	for(ll i=n; i>=j; i--)
#define ll long long
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define vvc vector<vc>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<ll, ll>
#define vpii vector<pii>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define sti set<int>
#define stl set<ll>
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define input(a, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define output(a, n)           \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << " ";
#define star   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define nl cout << "\n"
#define yes  cout<<"YES"<<endl
#define no  cout<<"NO"<<endl
#define prt(x)     cout<<x<<endl
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int ncr(int n, int r){
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    return p;}
vb sieve(ll n){
	vb is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for(ll i=2; i*i<=n; i++)
		if(is_prime[i])
			for(ll j=i*i; j<=n; j+=i)	is_prime[j] = false;

	return is_prime;}
ll binpow(ll a, ll b){
	if(b == 0)	return 1;
	ll res = binpow(a, b/2);
	if(b&1)	return res*res*a;
	else	return res*res;}
ll binpow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while(b > 0){
		if(b&1)	res = res * a % m;
        a = a * a % m;
        b >>= 1;
	}
	return res;}
ll lcm(ll a, ll b){
	return a*b/__gcd(a, b);}
ll accurateFloor(ll a, ll b) {
	ll val = a / b;
	while (val * b > a)
		val--;
	return val;}
// vll spf;
// // GIVE PRIME FACTORISATION OF X (BUT FIRST CALL SIEVE2 FROM MAIN)
// vector<int> getFactorization(int x){
//     vector<int> ret;
//     while (x != 1) {
//         ret.push_back(spf[x]);
//         x = x / spf[x];
//     }
//     return ret;}

// void sieve2(){
//     spf[1] = 1;
//     for (int i = 2; i < MAXN; i++)
 
//         // marking smallest prime factor for every
//         // number to be itself.
//         spf[i] = i;
 
//     // separately marking spf for every even
//     // number as 2
//     for (int i = 4; i < MAXN; i += 2)
//         spf[i] = 2;
 
//     for (int i = 3; i * i < MAXN; i++) {
//         // checking if i is prime
//         if (spf[i] == i) {
//             // marking SPF for all numbers divisible by i
//             for (int j = i * i; j < MAXN; j += i)
 
//                 // marking spf[j] if it is not
//                 // previously marked
//                 if (spf[j] == j)
//                     spf[j] = i;
//         }
//     }}














/*
 *****************************************************************
 ******************************************************************
 ******************************************************************
 ************************ WRITE CODE FROM HERE ********************
 ******************************************************************
 ******************************************************************
 *****************************************************************
*/









map<pii, int> m;
int rec(vvi &adj,int par,int i){
    int ans=0;
    for(int j=0;j<adj[i].size();j++){
        if(adj[i][j]==par)continue;
        int x=0;
        if(m[{par,i}]>m[{i,adj[i][j]}])
        x++;
        ans=max(ans,x+rec(adj,i,adj[i][j]));
    }
    return ans;
}



void solve(){
	ll n; cin>>n;
	vvll adj(n+1);
	m.clear();
	rep(i, 1, n) {
	   ll x,y; cin>>x>>y;
	   m[{x,y}]=i; m[{y,x}]=i;
	   adj[x].push_back(y);
	   adj[y].push_back(x);
	}
	int res = INT_MIN;
	for(int i=0;i<adj[1].size();i++){
	   res=max(res, rec(adj,1,adj[1][i]));
	}
	prt(res+ 1);
}




// CODE HERE
signed main() {
    star;
    ll t; cin>>t; while(t--){solve();}
    // solve();
	return 0;
}
























