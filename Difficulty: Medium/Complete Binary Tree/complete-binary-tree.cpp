class Solution {
  public:
    bool isCompleteBT(Node* root) {
        if (!root) return true;
        
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;
        
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if (temp == NULL) {
                nullFound = true;
            } else {
                if (nullFound) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        return true;
    }
};