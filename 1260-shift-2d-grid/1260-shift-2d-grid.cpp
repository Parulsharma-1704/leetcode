class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int m=grid.size();
        int n=grid[0].size();
        vector<int>temp(m*n);
        int y=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[y++]=grid[i][j];
            }
        }
        k=k%(m*n);
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());

       
       int x=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=temp[x++];
            }
        }
        

        return grid;
    }
};