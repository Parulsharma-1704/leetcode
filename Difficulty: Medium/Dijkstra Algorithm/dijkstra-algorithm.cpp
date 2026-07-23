class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto p : edges){
            int u=p[0];
            int v=p[1];
            int c=p[2];
            
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>Cost(V,1e9);
        
        Cost[src]=0;
        minHeap.push({0,src});
        
        while(!minHeap.empty()){
            auto node=minHeap.top();
            minHeap.pop();
            int cost=node.first;
            int next=node.second;
            
            for(auto x : adj[next]){
                int nn=x.first;
                int nc=x.second;
                
                if(cost+nc < Cost[nn]){
                    Cost[nn]=cost+nc;
                    minHeap.push({cost+nc,nn});
                }
            }
        }
        return Cost;
    }
};