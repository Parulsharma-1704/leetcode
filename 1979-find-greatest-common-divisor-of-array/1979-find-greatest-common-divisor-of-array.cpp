class Solution {
    int hcf(int num1, int num2){
        int a,b;
        b=(num1>num2)?num1:num2;
        a=(num1<num2)?num1:num2;

        while(b%a!=0){
            int ans=b%a;
            b=a;
            a=ans;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int minVal=INT_MAX;
        int maxVal=0;

        for(int x : nums){
            minVal=min(minVal,x);
            maxVal=max(maxVal,x);
        }

        return hcf(minVal,maxVal);
    }
};