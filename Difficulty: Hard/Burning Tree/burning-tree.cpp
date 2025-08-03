/*
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
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, bool> visited;
    
    void inOrder(Node* root){
        if(!root) return;
        
        if(root->left){
            parent[root->left] = root;
            inOrder(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            inOrder(root->right);
        }
    }
    
    Node* findNode(Node* root, int& target){
        if(!root) return NULL;
        if(root->data == target) return root;
        
        Node* left = findNode(root->left, target);
        if (left != NULL) return left;
        
        return findNode(root->right, target);
    }
    
    int solve(Node* root, int& target){
        // find target element
        Node* targetNode = findNode(root, target);
        if(!targetNode) return -1;
        
        //bfs from target level
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            
            while (n--) {
                Node* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                if (curr->right && visited[curr->right] == false) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            level++;
        }
        
        return level-1;
    }
    int minTime(Node* root, int target) {
        parent.clear();
        visited.clear();
        
        inOrder(root);
        return solve(root, target);
    }
};