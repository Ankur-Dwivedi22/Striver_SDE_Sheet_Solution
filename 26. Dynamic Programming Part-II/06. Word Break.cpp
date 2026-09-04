// Memoisation 
// TC : O(N ^ 3)
// SC : O(N) + O(N) + O(N)

class Solution {
public:
    bool f(int ind, string &s, unordered_map<string,int> &mp, vector<int> &dp){
        if(ind == s.size()){
            return true;
        }
        if(mp[s]) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int l=1; l<=s.size(); l++){
            if(mp[s.substr(ind, l)] && f(ind+l, s, mp, dp)){
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(string word : wordDict){
            mp[word]++;
        }
        int n = s.size();
        vector<int> dp(n+1, -1);
        return f(0,s,mp,dp);
    }
};

// Tabulation
// TC : O(N ^ 3)
// SC : O(N) + O(N)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> mp;
        for(string &word : wordDict){
            mp[word]++;
        }

        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && mp[s.substr(j, i-j)]){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};

