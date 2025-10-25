/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    bool isSame(Node* root, Node* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->data != subRoot->data) return false;
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
    bool isSubTree(Node* root, Node* subtree) {
        if (!subtree) return true;
        if(!root) return false;
        
        if(isSame(root, subtree)) return true;
        
        return isSubTree(root->left, subtree) || isSubTree(root->right, subtree);
    }
};