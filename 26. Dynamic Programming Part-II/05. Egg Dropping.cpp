// Approach : Recursion
// TC : Exponential
// SC : O(N)
class Solution {
public:
    int find(int k, int n){
        if(n == 0 || n == 1){
            return n;
        }
        if(k == 1){
            return n;
        }

        int ans = 1e9;
        for(int i=1; i<=n; i++){
            int temp = 1 + max(find(k-1, i-1) , find(k, n-i));
            ans = min(ans, temp);
        }

        return ans;
    }

    int superEggDrop(int k, int n) {
        return find(k, n);
    }
};

// Approach : Memoisation
// TC : O(K * N * N)
// SC : O(N) + O(K * N)
class Solution {
public:
    int find(int k, int n, vector<vector<int>> &dp){
        if(n == 0 || n == 1){
            return n;
        }
        if(k == 1){
            return n;
        }

        if(dp[k][n] != -1) return dp[k][n];

        int ans = 1e9;
        for(int i=1; i<=n; i++){
            int temp = 1 + max(find(k-1, i-1, dp) , find(k, n-i, dp));
            ans = min(ans, temp);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return find(k, n, dp);
    }
};

// Approach : Tabulation
// TC : O(K * N * N)
// SC : O(K * N)
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for (int k = 1; k <= K; k++) {
            dp[k][0] = 0;
            dp[k][1] = 1;
        }

        for (int n = 1; n <= N; n++) {
            dp[1][n] = n;
        }

        for (int k = 2; k <= K; k++) {
            for (int n = 2; n <= N; n++) {
                int ans = 1e9;
                for (int i = 1; i <= n; i++) {
                    int temp = 1 + max(dp[k-1][i-1], dp[k][n-i]);
                    ans = min(ans, temp);
                }

                dp[k][n] = ans;
            }
        }
        return dp[K][N];
    }
};

// Approach : Tabulation + Binary Search
// TC : O(K * N * logN)
// SC : O(K * N)
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for (int k = 1; k <= K; k++) {
            dp[k][0] = 0;
            dp[k][1] = 1;
        }

        for (int n = 1; n <= N; n++) {
            dp[1][n] = n;
        }

        for (int k = 2; k <= K; k++) {
            for (int n = 2; n <= N; n++) {
                int ans = 1e9;
                int lo = 1, hi = n;
                while(lo <= hi){
                    int mid = lo + (hi - lo) / 2;
                    int eggBreak = dp[k-1][mid-1];
                    int eggNotBreak = dp[k][n-mid];
                    int temp = 1 + max(eggBreak, eggNotBreak);
                    if(eggBreak < eggNotBreak){
                        lo = mid+1;
                    }
                    else{
                        hi = mid-1;
                    }
                    ans = min(ans, temp);
                }

                dp[k][n] = ans;
            }
        }
        return dp[K][N];
    }
};

// Approah : Optimised DP
// TC : O(K * M)
// SC : O(K)
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<long long> dp(k+1, 0);
        int ans = 0;

        while(dp[k] < n){
            ans++;

            for(int i=k; i>=1; i--){
                dp[i] = 1 + dp[i-1] + dp[i];
            }
        }

        return ans;
    }
};
