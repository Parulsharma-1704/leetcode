/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    Node* helper(Node* root, Node* n1, Node* n2){
        if((n1->data < root->data && n2->data > root->data) || 
        (n1->data > root->data && n2->data < root->data)){
            return root;
        }
        Node* left=NULL;
        if(n1->data < root->data && n2->data < root->data){
            left=helper(root->left,n1,n2);
        }
        Node* right=NULL;
        if(n1->data > root->data && n2->data > root->data){
            right=helper(root->right,n1,n2);
        }
        if(left==NULL && right==NULL){
            return root;
        }
        return left?left : right;
    }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
         return helper(root,n1,n2);
    }
};