//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
 vector<vector<int>> dp(100,vector<int> (100000,-1));
class Solution{   
public:

  
    bool fun(int n,int sum,vector<int> &v)
    {
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(n==0 && sum==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        if(v[n]>sum)
        {
            return dp[n][sum]=fun(n-1,sum,v);
        }
        else
        {
            return dp[n][sum]=fun(n-1,sum-v[n],v) || fun(n-1,sum,v);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
     
        return fun(arr.size()-1,sum,arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends