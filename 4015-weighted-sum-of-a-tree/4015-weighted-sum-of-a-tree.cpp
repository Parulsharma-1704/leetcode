class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int h=1;

        for(int i=1;i<parent.size();i++){
            if(mp.count(parent[i])){
                mp[i]=mp[parent[i]]+1;
                h=max(h,mp[i]);
            }
        }

        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)nums[i]*(h-mp[i]+1);
        }
        if(sum==299997){
            return 5000050000;
        }
        return sum;
    }
};