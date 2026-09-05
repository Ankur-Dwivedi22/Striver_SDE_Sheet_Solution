// DP + Binary Search
// TC : O(N * logN)
// SC : O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        vector<int> starts;
        for (int i = 0; i < n; i++) {
            v.push_back({startTime[i], endTime[i], profit[i]});
            starts.push_back(startTime[i]);
        }
        sort(v.begin(), v.end());
        sort(starts.begin(), starts.end());

        vector<int> dp(n + 1, 0);

        for (int ind = n-1; ind >= 0; ind--) {
            int skip = dp[ind+1];
            int next = lower_bound(starts.begin(), starts.end(), v[ind][1]) - starts.begin();
            int pick = v[ind][2] + dp[next];
            dp[ind] = max(pick, skip);
        }

        return dp[0];
    }
};
