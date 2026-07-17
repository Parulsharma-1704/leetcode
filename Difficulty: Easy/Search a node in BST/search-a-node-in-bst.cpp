/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    bool helper(Node* root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data == key){
            return true;
        }
        int r=false,l=false;
        if(root->data < key){
            r=helper(root->right,key);
        }
        else{
            l=helper(root->left,key);
        }
        return l || r;
    }
  public:
    bool search(Node* root, int key) {
        // code here
        return helper(root,key);
    }
};