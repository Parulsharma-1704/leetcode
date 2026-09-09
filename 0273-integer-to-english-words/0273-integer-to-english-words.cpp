class Solution {
    
public:
    vector<string> ones={"", "One", "Two", "Three", "Four", "Five", "Six"
    , "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
    "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string>tens={"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numLess1000(int num){
        string res="";
        if(num>=100){
            if (!res.empty()) res += " ";
            res+=numLess1000(num/100)+" Hundred";
            num=num%100;
        }
        if(num>=20){
            if (!res.empty()) res += " ";
            res+=tens[(num/10)];
            num=num%10;
        }
        if(num>0){
            if (!res.empty()) res += " ";
            res+=ones[num];
        }
        return res;
    }
    
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        string res="";

        if(num>=1000000000){
            if (!res.empty()) res += " ";
            res+=numLess1000(num/1000000000)+" Billion";
            num=num%1000000000;
        }
        if(num>=1000000){
            if (!res.empty()) res += " ";
            res+=numLess1000(num/1000000)+" Million";
            num=num%1000000;
        }
        if(num>=1000){
            if (!res.empty()) res += " ";
            res+=numLess1000(num/1000)+" Thousand";
            num=num%1000;
        }

        if(num>0){
            if (!res.empty()) res += " ";
            res+=numLess1000(num);
        }
        return res;
    }
};