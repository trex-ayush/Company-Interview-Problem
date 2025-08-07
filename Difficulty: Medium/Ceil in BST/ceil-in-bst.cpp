/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

// 10 5 11 4 7 N N N N N 8
// 6
// 3 1 4 N 2 N N N N
// 15
void solve(Node* root, int k, int& result){
    if(!root) return;
    
    if(root->data == k){
        result = k;
        return;
    }
    if(root->data > k && root->data < result){
        result = root->data;
    }
    solve(root->left, k, result);
    solve(root->right, k, result);
}

int findCeil(Node* root, int k) {
    if(!root) return -1;
    
    int result = INT_MAX;
    
    solve(root, k, result);
    
    return (result == INT_MAX) ? -1 : result;
}