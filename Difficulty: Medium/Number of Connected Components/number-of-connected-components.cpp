class Solution {
    void dfs(vector<vector<int>>&adj, vector<int>&visited, int node){
        visited[node]=1;
        
        for(int x : adj[node]){
            if(!visited[x]){
                dfs(adj,visited,x);
            }
        }
    }
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto x : edges){
            int u=x[0];
            int v=x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        
        return count;
    }
};