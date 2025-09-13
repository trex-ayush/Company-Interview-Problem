class Solution {
  public:
    int findCeil(Node* root, int x) {
        if(!root) return -1;
        int result = -1;
        
        Node* temp = root;
        
        while(temp){
            if(temp->data == x) return x;
            else if(temp->data > x){
                result = temp->data;
                temp = temp->left;
            }else temp = temp->right;
        }
        return result;
    }
};
