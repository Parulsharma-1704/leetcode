class Solution {
    int prodOfDigits(int n){
        int prod=1;
        while(n>0){
            prod*=n%10;
            n=n/10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        
        for(int i=0;i<=10;i++){
            if((prodOfDigits(n+i))%t==0){
                return n+i;
            }
        }
       return 0;
    }
};