class Solution {
    void dfs(int i, vector<vector<int>>&adj, vector<int>&visited, stack<int>&st){
        visited[i]=1;
        
        for(int x : adj[i]){
            if(!visited[x]){
                visited[x]=1;
                dfs(x,adj,visited,st);
            }
        }
        st.push(i);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
        }
        
        stack<int>st;
        
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};