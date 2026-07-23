class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>>adj(n);
        for(auto p : times){
            int u=p[0]-1;
            int v=p[1]-1;
            int c=p[2];
            
            adj[u].push_back({v,c});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>Cost(n,1e9);

        Cost[k-1]=0;
        minHeap.push({0,k-1});

        while(!minHeap.empty()){
            auto node=minHeap.top();
            minHeap.pop();
            int curr=node.second;
            int currCost=node.first;

            for(auto x : adj[curr]){
                int next=x.first;
                int nextCost=x.second;

                if(currCost+nextCost < Cost[next]){
                    Cost[next]=currCost+nextCost;
                    minHeap.push({currCost+nextCost,next});
                }
            }
        }
        int minTime=*max_element(Cost.begin(),Cost.end());

        if(minTime>=1e9){
            return -1;
        }
        return minTime;
    }
};