// Memoisation
// TC : O(N * N)
// SC : O(N * N) + O(N)

class Solution {
  public:
    int solve(int len, vector<int> &price, vector<int> &dp){
        if(len == 0){
            return 0;
        }
        
        if(dp[len] != -1) return dp[len];
        
        int ans = 0;
        for(int k=1; k<=len; k++){
            ans = max(ans, price[k-1] + solve(len-k, price, dp));
        }
        
        return dp[len] = ans;
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n+1, -1);
        return solve(n, price, dp);
    }
};

// Tabulation
// TC : O(N * N)
// SC : O(N)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n+1, 0);
        
        for(int len=1; len<=n; len++){
            int ans = 0;
            for(int k=1; k<=len; k++){
                ans = max(ans, price[k-1] + dp[len-k]);
            }
            
            dp[len] = ans;  
        }
        
        return dp[n];
    }
};
