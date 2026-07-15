class Solution {
    bool isSafe(vector<string>& b, int n, int row, int col){

        for(int i=0;i<row;i++){
            if(b[i][col]=='Q'){
                return false;
            }
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0 ; i-- , j--){
            if(b[i][j]=='Q'){
                return false;
            }
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i-- , j++){
            if(b[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& b, int n, int row){
        if(row==n){
            ans.push_back(b);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(b,n,row,col)){
                b[row][col]='Q';
                solve(ans,b,n,row+1);
                b[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>b(n,string(n,'.'));

        solve(ans,b,n,0);

        return ans;
    }
};