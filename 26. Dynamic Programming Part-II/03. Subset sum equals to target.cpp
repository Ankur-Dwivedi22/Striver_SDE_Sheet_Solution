// Subset sum equals to target
// TC : O(N * S)
// SC :O(N * S) + O(S)

class Solution {
  public:
    bool solve(int ind, int rem, vector<int> &arr, vector<vector<int>> &dp){
        if(rem == 0) return true;
        
        if(ind == 0){
            return (rem == arr[0]);
        }
        
        if(dp[ind][rem] != -1) return dp[ind][rem];
        
        bool skip = solve(ind-1, rem, arr, dp);
        bool pick = false;
        if(rem >= arr[ind]){
            pick = solve(ind-1, rem - arr[ind], arr, dp);
        }
        
        return dp[ind][rem] = skip || pick;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(n-1, sum, arr, dp);    
    }
};

// Subset Sums
// TC : O(2 ^ N)
// SC : O(2 ^ N)

class Solution {
  public:
    vector<int> ans;
    void solve(int ind, int sum, vector<int> &arr){
        if(ind == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        solve(ind+1, sum, arr);
        solve(ind+1, sum + arr[ind], arr);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        ans.clear();
        int n = arr.size();
        solve(0, 0, arr);
        return ans;
    }
};
