// Constructing minimum path
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                int up = 1e9, left = 1e9;
                if(i-1 >= 0) up = grid[i][j] + dp[i-1][j];
                if(j-1 >= 0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }

        vector<int> path;
        int i = m-1, j = n-1;
        while(i != 0 || j != 0){
            path.push_back(grid[i][j]);
            if(i == 0) j--;
            else if(j == 0) i--;
            else if(dp[i-1][j] < dp[i][j-1]) i--;
            else j--;
        }
        path.push_back(grid[0][0]);
        reverse(path.begin(), path.end());
        for(int p : path){
            cout<<p<<" ";
        }
        return dp[m-1][n-1];
    }
};

// Approach : Memoisation
// TC : O(M * N)
// SC : O(M * N) + O(M + N)

class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int left = 1e9 , up = 1e9;
        if(j-1 >= 0){
            left = grid[i][j] + f(i,j-1,grid,dp);
        }
        if(i-1 >= 0){
            up = grid[i][j] + f(i-1,j,grid,dp);
        }
        return dp[i][j] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1,n-1,grid,dp);
    }
};

// Approach : Tabulation
// TC : O(M * N)
// SC : O(M * N)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                int up = 1e9, left = 1e9;
                if(i-1 >= 0) up = grid[i][j] + dp[i-1][j];
                if(j-1 >= 0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};

// Approach : Space Optimisation
// TC : O(M * N)
// SC : O(N)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0), curr(n, 0);
        curr[0] = dp[0] = grid[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                int up = 1e9, left = 1e9;
                if(i-1 >= 0) up = grid[i][j] + dp[j];
                if(j-1 >= 0) left = grid[i][j] + curr[j-1];
                curr[j] = min(up, left);
            }
            dp = curr;
        }

        return dp[n-1];
    }
};

