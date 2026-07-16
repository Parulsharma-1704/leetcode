/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<int,Node*>>q;
        
        if(root==NULL){
            return ans;
        }
        
        q.push({0,root});
        
        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                auto temp=q.front();
                q.pop();
                
                mp[temp.first]=temp.second->data;
                
                if(temp.second->left){
                    q.push({temp.first-1,temp.second->left});
                }
                if(temp.second->right){
                    q.push({temp.first+1,temp.second->right});
                }
            }
        }
        
        for(auto &p : mp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};