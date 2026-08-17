class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int maxL=0;
        unordered_map<char,int>freq;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            maxL=max(maxL,r-l+1);
        }
        return maxL;
    }
};