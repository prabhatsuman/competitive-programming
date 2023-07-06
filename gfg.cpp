//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
    public:
        bool isGoodLength(const vector<vector<int>> &matrix, int length)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i <= rows - length; i++)
        {
            for (int j = 0; j <= cols - length; j++)
            {
                bool valid = true;
                for (int k = i; k < i + length; k++)
                {
                    for (int l = j; l < j + length; l++)
                    {
                        if (matrix[k][l] < length)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                        break;
                }
                if (valid)
                    return true;
            }
        }

        return false;
    }
        int maxGoodLength(vector<vector<int>>&matrix)
        {
            // Write your code here.
            int rows = matrix.size();
        int cols = matrix[0].size();
        int minLen = 1;
        int maxLen = min(rows, cols);
        int result = 0;

        while (minLen <= maxLen)
        {
            int mid = (minLen + maxLen) / 2;
            if (isGoodLength(matrix, mid))
            {
                result = mid;
                minLen = mid + 1;
            }
            else
            {
                maxLen = mid - 1;
            }
        }
        return result;
        }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,i,j;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        int ans=ob.maxGoodLength(a);
        cout<<ans<<endl;
    }
}

// } Driver Code Ends