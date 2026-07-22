class Solution {
    bool dfs(int i, vector<vector<int>>&adj, vector<int>&state){
        if(state[i]==2){
            return false;
        }
        if(state[i]==1){
            return true;
        }
        state[i]=1;
        
        for(int x : adj[i]){
                if(dfs(x,adj,state)){
                    return true;
                }
            
        }
        state[i]=2;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            
            adj[u].push_back(v);
        }
        vector<int>state(V,0);
        
        for(int i=0;i<V;i++){
            if(state[i]==0){
                if(dfs(i,adj,state)){
                    return true;
                }
            }
        }
        
        return false;
    }
};