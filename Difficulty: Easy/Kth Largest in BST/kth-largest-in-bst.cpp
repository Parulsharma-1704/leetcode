/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    void inorder(Node* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->right,ans);
        ans.push_back(root->data);
        inorder(root->left,ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        // code here
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }
};