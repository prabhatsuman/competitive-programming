#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n  ;
        cin>>n; 
        string s;
        cin>>s;
 
        string ans ="";
 
        if(s[0]!='9'){
            for(int i=0;i<n;i++){
                int digit = s[i]-'0';
                ans += (9-digit)+'0';
            }
        }
        else{
            int next = 1 ;
            int c =0 ;
            for(int i=n-1;i>=0;i--){
                int x = s[i]-'0';
                // x+=c;
                // if(x>1){
                //     int y = 11-x;
                //     c= 1;
                //     ans+=(y+'0');
                // }
                // else {
                //     c =0 ;
                //     int y = 1-x;
                //     ans += (y+'0');
                // }
                if(next == 1){
                    if(x>1){
                        int y = 11-x;
                        ans += y+'0';
                        next = 0 ;
                    }
                    else{
                        int y = 1-x;
                        ans += y+'0';
                    }
                }
                else{
                    if(x==0){
                        ans += '0' ;
                        next = 1;
                    }
                    else{
                        int y = 10-x;
                        ans += y+'0';
                        next = 0 ;
                    }
                }
                // cout<<ans<<endl;
            }
            reverse(ans.begin() , ans.end());
        }
        cout<<ans<<endl;
    }
return 0;
}