// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    int solve(Node* root, int& maxSum){
        if(!root) return 0;
        
        int left  = max(0, solve(root -> left, maxSum));
        int right = max(0, solve(root -> right, maxSum));
        
        maxSum = max(maxSum, root -> data + left + right);
        
        return root -> data + max(left, right);
    }
    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
