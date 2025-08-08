// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    Node* solve(int pre[], int& i, int upperBound, int n) {
        if (i >= n || pre[i] > upperBound) return NULL;
        
        Node* root = newNode(pre[i]);
        i++;
        
        root->left = solve(pre, i, root->data, n);
        root->right = solve(pre, i, upperBound, n);
        
        return root;
    }
    
    Node* Bst(int pre[], int n) {
        int i = 0;
        return solve(pre, i, INT_MAX, n);
    }
};