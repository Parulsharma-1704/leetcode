class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>ans;

        for(long long x : nums){
            while(!ans.empty() && x==ans.back()){
                x=ans.back()+x;
                ans.pop_back();
                
            }
            ans.push_back(x);
        }
        return ans;
    }
};