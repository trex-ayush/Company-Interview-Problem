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
    bool isSymmetric(Node* root) {
        if (!root) return true;
        
        queue<Node*> leftTree;
        queue<Node*> rightTree;
        
        leftTree.push(root->left);
        rightTree.push(root->right);
        
        while (!leftTree.empty() && !rightTree.empty()) {
            Node* leftNode  = leftTree.front();
            Node* rightNode = rightTree.front();
            leftTree.pop();
            rightTree.pop();
            
            if (leftNode == NULL && rightNode == NULL) continue;
            
            if (leftNode == NULL || rightNode == NULL) return false;
            
            if (leftNode->data != rightNode->data) return false;
            
            leftTree.push(leftNode->left);
            leftTree.push(leftNode->right);
            rightTree.push(rightNode->right);
            rightTree.push(rightNode->left);
        }
        
        return true;
    }
};