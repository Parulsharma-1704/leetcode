class Solution {
    void isConnected(vector<vector<int>>&adj, int node, vector<int>&visited, int &e, int &v){
        visited[node]=1;
        v++;

        for(int x : adj[node]){
            e++;
            if(!visited[x]){
                isConnected(adj,x,visited,e,v);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        int count=0;
        vector<int>visited(n,0);

        for(int i=0;i<n;i++){
            int e=0,v=0;
            if(!visited[i]){
                isConnected(adj,i,visited,e,v);

                e=e/2;
                int y=(v*(v-1))/2;
                if(y==e){
                    count++;
                }
            }
        }
        return count;
    }
};