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

// Optimised DP
// TC : O(N * L^2)
// SC : O(N) + O(N)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> mp;
        int mxlen = 0;
        for(string &word : wordDict){
            mp[word]++;
            mxlen = max(mxlen, (int)word.size());
        }

        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int len=1; len<=i && len<=mxlen; len++){
                if(dp[i-len] && mp[s.substr(i-len, len)]){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// DP + Trie
// TC : O(N * L)
// SC : O(N + T)

class Trie {
public:
    bool isEnd;
    Trie* children[26];

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    void insert(Trie* root, string &s){
        Trie* node = root;
        for(char c : s){
            int ind = c - 'a';
            if(node->children[ind] == nullptr){
                node->children[ind] = new Trie();
            }
            node = node->children[ind];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;

        Trie* root = new Trie();

        for(string &word : wordDict){
            root->insert(root, word);
        }

        for(int i=0; i<n; i++){
            if(dp[i] == 0) continue;
            Trie* curr = root;
            for(int j=i; j<n; j++){
                int ind = s[j] - 'a';
                if(curr->children[ind] == nullptr){
                    break;
                }

                curr = curr->children[ind];
                if(curr->isEnd){
                    dp[j+1] = 1;
                }
            }
        }

        return dp[n];
    }
};


