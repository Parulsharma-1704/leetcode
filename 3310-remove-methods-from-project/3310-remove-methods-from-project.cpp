class Solution {
    void dfs(int i, vector<vector<int>>&adj, unordered_set<int>&s, vector<int>&visited){
        visited[i]=1;

        s.insert(i);
        for(int x : adj[i]){
            if(!visited[x]){
                visited[x]=1;
                dfs(x,adj,s,visited);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        unordered_set<int>s;
        for(auto p : invocations){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
        }
        vector<int>visited(n);
        dfs(k,adj,s,visited);

       for(int i=0;i<n;i++){
            if(!visited[i]){
                for(int x : adj[i]){
                    if(s.count(x)){
                        s.clear();
                    }
                }
            }
       }

        vector<int>ans;
       
            for(int i=0;i<n;i++){
                if(!s.count(i)){
                    ans.push_back(i);
                }
            }
     
        
        return ans;
    }
};