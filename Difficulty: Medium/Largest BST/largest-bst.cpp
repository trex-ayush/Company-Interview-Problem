class Mydata{
public:
    int minNode;
    int maxNode;
    int maxSize;

    Mydata(int minNode, int maxNode, int maxSize) {   
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    // Post order, why?
    // here we will get the informmation about the left and right so that we can compare it with node
    Mydata solve(Node* root){
        if(!root) return Mydata(INT_MAX, INT_MIN, 0);
        
        Mydata left  = solve(root->left);
        Mydata right = solve(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode) {
            // valid BST
            return Mydata(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        return Mydata(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root) {
        return solve(root).maxSize;   
    }
};