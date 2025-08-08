/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void countNodes(Node* root, int& count) {
        if (!root) return;
        count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }
    void solve(Node* root, int k, priority_queue<int, vector<int>, greater<int>>& pq){
        if(!root) return;
        
        pq.push(root->data);
        if(pq.size() > k) pq.pop();
        
        if(root -> left)  solve(root -> left, k, pq);
        if(root -> right) solve(root -> right, k, pq);
    }
    int kthLargest(Node *root, int k) {
        int nodeCount = 0;
        countNodes(root, nodeCount);
        if (nodeCount < k) return -1;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        solve(root, k, pq);
        return pq.top();
    }
};