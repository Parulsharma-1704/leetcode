class Solution {
    double total(vector<int>&prices){
        double sum=0;
        for(int x : prices){
            sum+=x;
        }
        return sum;
    }
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        
        int n=prices.size();
        int m=discounts.size();

        double sum=total(prices);
        
        int j=n-1;
       for(int i=m-1;i>=0;i--){
            if(j>=0){
                sum-=prices[j];
                sum+=((prices[j]*(100-discounts[i]))*1.0)/100;
                j--;
            }
       }

       
       return sum;
    }
};