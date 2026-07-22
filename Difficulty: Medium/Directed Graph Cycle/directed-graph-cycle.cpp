class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>inDegree(V,0);
        
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }   
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int x : adj[node]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()<V){
            return true;
        }
        return false;
    }
};