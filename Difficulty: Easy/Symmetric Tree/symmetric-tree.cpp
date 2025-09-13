/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* p, Node* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->data != q->data) return false;
        return solve(p->left, q->right) && solve(p->right, q->left);
    }
    bool isSymmetric(Node* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        
        return solve(root->left, root->right);
    }
};