class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(char x : word){
            mp[x]++;
        }

        vector<int>temp;

        int ans=0;

        for(auto p : mp){
            char ch=p.first;
            int num=p.second;
            
            temp.push_back(num);
        }

        sort(temp.begin(),temp.end(),greater<int>());

        for(int i=0;i<temp.size();i++){
            ans+=((i/8)+1)*temp[i];
        }

        return ans;
    }
};