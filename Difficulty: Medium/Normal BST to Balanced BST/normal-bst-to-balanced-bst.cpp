/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* convertSortedArrayToBST(vector<int>& arr, int i, int j){
        if(i > j) return NULL;
        
        int mid = i + (j - i)/2;
        Node* root  = new Node(arr[mid]);
        root->left  = convertSortedArrayToBST(arr, i, mid - 1);
        root->right = convertSortedArrayToBST(arr, mid + 1, j);
        
        return root;
    }
    void inorder(Node* root, vector<int>& res){
        if(!root) return;
        
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    Node* balanceBST(Node* root) {
        if(!root) return root;
        
        vector<int> vec;
        inorder(root, vec);
        
        return convertSortedArrayToBST(vec, 0, vec.size() - 1);
    }
};