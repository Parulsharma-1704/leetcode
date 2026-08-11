class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int maxSum=nums[0];
        unordered_set<int>s(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                break;
            }
            sum+=nums[i];
            maxSum=max(maxSum,sum);
        }

        while(s.count(maxSum)){
            maxSum++;
        }
        return maxSum;
    }
};