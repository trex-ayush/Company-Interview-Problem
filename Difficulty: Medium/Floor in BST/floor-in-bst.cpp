// Function to search a node in BST.
class Solution {
  public:
    int floor(Node* root, int k) {
        if(!root) return -1;
        int result = -1;
        
        while(root){
            if(root->data == k){
                result = root->data;
                break;
            }else if(root->data >= k){
                root = root->left;
            }else{
                result = root->data;
                root = root->right;
            }
        }
        
        return result;
    }
};