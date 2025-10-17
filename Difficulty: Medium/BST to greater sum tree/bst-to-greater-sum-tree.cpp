/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& val){
        if(!root) return;
        
        inorder(root->left, val);
        val.push_back(root->data);
        inorder(root->right, val);
    }
    void transformTree(Node *root) {
        if(!root) return;
        
        vector<int> val;
        inorder(root, val);
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* u = q.front();
            int temp = u->data;
            q.pop();
            
            int res = 0;
            for(int i = val.size() - 1; i >= 0; i--){
                if(val[i] > temp) res += val[i];
                else break;
            }
            
            u->data = res;
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        
    }
};