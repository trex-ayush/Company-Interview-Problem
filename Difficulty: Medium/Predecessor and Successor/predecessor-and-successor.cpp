/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> res;
    Node* findMax(Node* root){
        while (root && root->right) {
            root = root->right;
        }
        return root;
    }
    
    Node* findMin(Node* root){
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }
    
    void solve(Node* root, int k){
        if(!root) return;
        
        // case 1
        if(root->data < k){
            res[0] = root;
            solve(root->right, k);
        }else if(root->data > k){
            // case 2
            res[1] = root;
            solve(root->left, k);
        }else{
            // case 3
            // predecessor left mai maximum
            if(root->left)  res[0] = findMax(root->left);
            // successor -> right mai minium
            if(root->right) res[1] = findMin(root->right);
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        res.resize(2, NULL);
        
        solve(root, key);
        
        return res;
    }
};