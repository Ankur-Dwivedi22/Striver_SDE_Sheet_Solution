// Memoisation
// TC : O(N * T)
// SC : O(N * T) + O(T)

class Solution {
public:
    int solve(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp){
        if(sum == 0) return 1;

        if(ind == coins.size()){
            return (sum == 0);
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int skip = solve(ind+1, sum, coins, dp);
        int take = 0;
        if(sum >= coins[ind]){
            take = solve(ind, sum - coins[ind], coins, dp);
        }

        return dp[ind][sum] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(5001, -1));
        return solve(0, amount, coins, dp);
    }
};

// Tabulation
// TC : O(N * T)
// SC : O(N * T)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int ind=0; ind<=n; ind++){
            dp[ind][0] = 1;
        }

        for(int ind=n-1; ind>=0; ind--){
            for(int sum=0; sum<=amount; sum++){
                int skip = dp[ind+1][sum];
                int take = 0;
                if(sum >= coins[ind]){
                    take = dp[ind][sum - coins[ind]];
                }

                dp[ind][sum] = take + skip;
            }
        }

        return dp[0][amount];
    }
};

// Space Optimisation
// TC : O(N * T)
// SC : O(T)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount+1, 0), curr(amount+1, 0);
        for(int ind=0; ind<=n; ind++){
            dp[0] = 1;
        }

        for(int ind=n-1; ind>=0; ind--){
            curr[0] = 1;
            for(int sum=1; sum<=amount; sum++){
                long long skip = dp[sum];
                long long take = 0;
                if(sum >= coins[ind]){
                    take = curr[sum - coins[ind]];
                }

                curr[sum] = take + skip;
            }
            dp = curr;
        }

        return dp[amount];
    }
};
