/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    int maxWidth(Node* root) {
        if(!root)return 0;
        queue<Node*>q;
        q.push(root);
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            ans=max(n,ans);
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return ans;
    }
};