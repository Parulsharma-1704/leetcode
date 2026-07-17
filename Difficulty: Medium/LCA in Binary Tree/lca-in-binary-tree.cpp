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
    Node* helper(Node* root, int n1, int n2){
        if(root==nullptr || root->data==n1 || root->data==n2){
            return root;
        }
        Node* left=helper(root->left,n1,n2);
        Node* right=helper(root->right,n1,n2);
        
        if(left && right){
            return root;
        }
        return (left)?left:right;
    }
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        return helper(root,n1,n2);
    }
};