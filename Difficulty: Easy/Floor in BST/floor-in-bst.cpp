/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    void floor(Node* root, int k, int &ans){
        if(root==NULL){
            return;
        }
        if(root->data <= k){
            ans=root->data;
            floor(root->right,k,ans);
        }
        else{
            floor(root->left,k,ans);
        }
    }
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans=-1;
        floor(root,k,ans);
        return ans;
    }
};