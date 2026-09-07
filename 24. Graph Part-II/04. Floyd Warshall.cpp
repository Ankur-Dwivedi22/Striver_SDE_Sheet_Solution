// TC : O(V ^ 3)
// SC : O(V ^ 2)

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        // FOR DETECTING NEGATIVE CYCLE
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j && dist[i][j] < 0){
                    return;
                }
            }
        }
    }
};
