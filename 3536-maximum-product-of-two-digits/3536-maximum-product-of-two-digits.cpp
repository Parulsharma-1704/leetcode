class Solution {
public:
    int maxProduct(int n) {

        int num=n;
        int l=0;
        int sl=0;
        while(n!=0){
            int r=n%10;
            if(r>=l){
                sl=l;
                l=r;
            }
            else if(r>sl && r<l){
                sl=r;
            }
            n=n/10;
        }
       
       return l*sl;

    }
};