/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *x) {
        int res = -1;
        solve
        while(root) {
            if(root->data > x->data) {
                res = root->data;
                root = root->left;
            }else root = root->right;
        }
        
        return res;
    }
};