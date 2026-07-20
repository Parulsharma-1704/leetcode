/*
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
    bool helper(Node* root, int &min_val, int &max_val){
      if(root==NULL){
          return true;
      }
      if(root->data <= min_val || root->data >= max_val){
          return false;
      }
      bool left=helper(root->left,min_val,root->data);
      bool right=helper(root->right,root->data,max_val);
      
      return left && right;
    }
  public:
    bool isBST(Node* root) {
        // code here
        int min_val=INT_MIN;
        int max_val=INT_MAX;
        return helper(root,min_val,max_val);
        
    }
};