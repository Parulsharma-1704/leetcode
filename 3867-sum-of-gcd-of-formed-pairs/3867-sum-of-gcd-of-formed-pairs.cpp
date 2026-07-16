class Solution {
    int gcd(int num1, int num2){
        int a,b;
        b= (num1>num2) ? num1 : num2;
        a= (num1<num2) ? num1 : num2;

        while(b%a!=0){
            int ans=b%a;
            b=a;
            a=ans;
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGcd(n);
        int maxi=0;
        for(int i=0;i<n;i++){
           maxi=max(maxi,nums[i]);
           prefixGcd[i]=gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());

        int l=0,r=n-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};