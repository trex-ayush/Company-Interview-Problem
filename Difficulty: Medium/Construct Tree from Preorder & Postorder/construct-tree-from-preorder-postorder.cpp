/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder) {
        if(prestart > preend) {
            return NULL;
        }
        
        Node* root = new Node(preorder[prestart]);
        if(prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart+1]; 
        
        int j = poststart;
        while(postorder[j] != nextNode) {
            j++;
        }
        
        int num = j - poststart + 1;
        
        root->left = solve(prestart+1, poststart, prestart+num, preorder, postorder);
        root->right = solve(prestart+num+1, j+1, preend, preorder, postorder);
        
        return root;
    }
    Node *constructTree(vector<int> &preorder, vector<int> &postorder) {
        int n = preorder.size();
        return solve(0, 0, n-1, preorder, postorder);
    }
};