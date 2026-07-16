class Solution {
    int gcd(int num1, int num2){
        int a,b;
        b=(num1>num2) ? num1 : num2;
        a=(num1<num2) ? num1 : num2;

        while(b%a!=0){
            int ans=b%a;
            b=a;
            a=ans;
        }
        return a;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;

        int count=0;
        int i=1;

        while(count<(n+n)){
            if(i%2==0){
                sumEven+=i;
            }
            else{
                sumOdd+=i;
            }
            i++;
            count++;
        }
        return gcd(sumOdd,sumEven);
    }
};