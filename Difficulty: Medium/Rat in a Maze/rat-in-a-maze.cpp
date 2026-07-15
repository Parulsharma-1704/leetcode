class Solution {
    void helper(int x, int y, vector<vector<int>>&maze, vector<string>&ans, string &curr ){
       int m=maze.size();
       int n=maze[0].size();
        if(x==m-1 && y==n-1){
            ans.push_back(curr);
            return;
        }
        
        int temp=maze[x][y];
        maze[x][y]=-1;
        
        vector<int>dir={0,1,0,-1,0};
        vector<char>d={'R','D','L','U'};
        
        for(int i=0;i<4;i++){
            int nx=x+dir[i];
            int ny=y+dir[i+1];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny]!=-1 && maze[nx][ny]==1){
                curr.push_back(d[i]);
                helper(nx,ny,maze,ans,curr);
                curr.pop_back();
            }
        }
        maze[x][y]=temp;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int m=maze.size();
        int n=maze[0].size();
        if(maze[0][0]==0 || maze[m-1][n-1]==0){
            return {};
        }
        
        
        vector<string>ans;
        string curr="";
        helper(0,0,maze,ans,curr);
        sort(ans.begin(),ans.end());
        return ans;
    }
};