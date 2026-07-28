class Solution {
public:
    int maxProduct(int n) {

        int num=n;
       vector<int>arr;
        while(n!=0){
            arr.push_back(n%10);
            n=n/10;
        }
        // if(to_string(num).length()==2){
        //     return prod;
        // }
        // int max_val=0;
        // while(num!=0){
        //     if(num%10 != 0){
        //         max_val=max(max_val,prod/(num%10));
        //     }
        //     num/=10;
        // }
        // return max_val;
        int m=arr.size();
       sort(arr.begin(),arr.end());
       return arr[m-2]*arr[m-1];

    }
};