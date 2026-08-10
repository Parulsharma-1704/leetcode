class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        set<int>temp;
        for(int x : nums){
            temp.insert(x);
        }
        int minNum=INT_MAX;
        int maxNum=0;
        for(int x : nums){
            minNum=min(minNum,x);
            maxNum=max(maxNum,x);
        }

        int currNum=minNum;
        while(currNum<=maxNum){
            if(!temp.count(currNum)){
                ans.push_back(currNum);
            }
            currNum=currNum+1;
        }
        return ans;
    }
};