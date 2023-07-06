//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    long sum=0;
   
    int i=0;
    void solve(vector<int> &res, vector<int> &arr,int n,int i)
    {
        if(i==n)
        {
            return;
        }
        sum+=arr[i];
        res.push_back(sum);
        solve(res,arr,n,i+1);
        sum-=arr[i];
        solve(res,arr, n, i);
        res.push_back(sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
         vector<long> res;
        solve(res,arr,N,i);
        return res;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends