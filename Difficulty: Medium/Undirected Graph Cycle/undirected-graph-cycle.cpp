class Solution {
    bool bfs(int i, vector<vector<int>>&adj, vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.first;
            int parent=node.second;
            
            for(int y : adj[x]){
                if(!visited[y]){
                    visited[y]=1;
                    q.push({y,x});
                }
                else if(parent!=y){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};