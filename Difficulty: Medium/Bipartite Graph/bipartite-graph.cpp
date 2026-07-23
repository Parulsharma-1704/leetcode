class Solution {
    bool helper(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&color){
        visited[node]=1;
        
        for(int x : adj[node]){
            if(!visited[x]){
                color[x]=1-color[node];
                if(!helper(x,adj,visited,color)){
                    return false;
                }
            }
            else if(color[x]==color[node]){
                return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V,0);
        vector<int>color(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(!helper(i,adj,visited,color)){
                    return false;
                }
            }
        }
        return true;
    }
};