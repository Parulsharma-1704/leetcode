class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()==1){
            return s;
        }
        map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        string ans="";

        for(auto p : mp){
            char ch=p.first;
            int f=p.second;
            for(int i=0;i<f/2;i++){
                ans+=ch;
            }
        }

        for(auto p : mp){
            if(p.second%2==1){
                ans+=p.first;
            }
        }
        string temp;
        int n=s.size();
        int m=ans.size();
        temp=ans.substr(0,n-m);
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};