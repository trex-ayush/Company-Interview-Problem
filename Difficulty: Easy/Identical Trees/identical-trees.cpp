/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
         = nullptr;
    }
};
*/

class Solution {
  public:
    bool isIdentical(Node* p, Node* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        if(p->data != q->data) return false;
        
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
};