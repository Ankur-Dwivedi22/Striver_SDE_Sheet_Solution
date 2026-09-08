// TC : O(E * logE)
// SC : O(V + E)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0] , v = edge[1] , wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> vis(V, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto neighbor : adj[node]){
                int adjNode = neighbor.first;
                int edwt = neighbor.second;
                if(!vis[adjNode]){
                    pq.push({edwt, adjNode});
                }
            }
        }
        
        return sum;
    }
};

// For printing MST
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> vis(V, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, -1});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it[0], node = it[1], parent = it[2];
            
            if(vis[node] == 1) continue;
            sum += wt;
            vis[node] = 1;
            if(parent != -1){
                cout<<parent<<"-"<<node<<":"<<wt<<endl;
            }
            
            for(auto [adjNode, edwt] : adj[node]){
                if(!vis[adjNode]){
                    pq.push({edwt, adjNode});
                }
            }
        }
        
        return sum;
    }
};
