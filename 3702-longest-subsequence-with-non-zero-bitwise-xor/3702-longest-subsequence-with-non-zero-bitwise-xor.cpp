class Solution {
    int count=0;
    void helper(int i, vector<int>&nums, int res, vector<int>&curr){
        if(i==nums.size()){
            if(res!=0){
                int x=curr.size();
               count=max(count,x);
            }
            return;
        }
        curr.push_back(nums[i]);
        helper(i+1,nums,res^nums[i],curr);
        curr.pop_back();
        helper(i+1,nums,res,curr);
    }
public:
    int longestSubsequence(vector<int>& nums) {
        // int res=0;
        // vector<int>curr;
        // helper(0,nums,res,curr);
        // return count;


        int res=0;
        for(int x : nums){
            res^=x;
        }

        int maxL=0;

        if(res!=0){
            maxL=nums.size();
        }
        else{
            for(int i=0;i<nums.size();i++){
                int temp=res;
                temp^=nums[i];
                if(temp!=0){
                    maxL=nums.size()-1;
                }
            }
        }
        return maxL;
    }
};