/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    void solveMax(Node* root, int& maxi){
        maxi = max(root->data, maxi);
        if(root->right) solveMax(root->right, maxi);
    }
    int findMax(Node *root) {
        if(!root) return -1;
        int maxi = INT_MIN;
        
        solveMax(root, maxi);
        
        return maxi;
    }
    
    void solveMin(Node* root, int& mini){
        mini = min(root->data, mini);
        if(root->left) solveMin(root->left, mini);
    }
    int findMin(Node *root) {
        if(!root) return -1;
        int mini = INT_MAX;
        
        solveMin(root, mini);
        
        return mini;
    }
};