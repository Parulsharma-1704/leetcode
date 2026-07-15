/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    int helper(Node* root){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        return 1+max(left,right);
    }
  public:
    int height(Node* root) {
        // code here
        return helper(root)-1;
    }
};