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
    void traversal(Node *root, priority_queue<int,vector<int>,greater<int>>&minHeap){
        if(root==NULL){
            return;
        }
        minHeap.push(root->data);
        traversal(root->left,minHeap);
        traversal(root->right,minHeap);
    }
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minHeap;
        traversal(root,minHeap);
        if(k>minHeap.size()){
            return -1;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};