class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int num=k;
        while(s.count(num)){
            num+=k;
        }
        return num;
    }
};