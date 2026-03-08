1// Company tags: Zepro
2// T.C: O(n)
3// S.C: O(h)
4class Node{
5public:
6    int minNode;
7    int maxNode;
8    int sum;
9
10    Node(int minNode, int maxNode, int sum) {   
11        this->minNode = minNode;
12        this->maxNode = maxNode;
13        this->sum = sum;
14    }
15};
16
17class Solution {
18public:
19    int ans = 0;
20    // Post order, why?
21    // here we will get the information about the left and right
22    // so that we can compare it with node
23    Node solve(TreeNode* root){
24        if(!root) return Node(INT_MAX, INT_MIN, 0);
25
26        Node left  = solve(root->left);
27        Node right = solve(root->right);
28
29        // check BST condition
30        if(left.maxNode < root->val && root->val < right.minNode) {
31            // Valid BST
32            int currSum = left.sum + right.sum + root->val;
33            ans = max(ans, currSum);
34
35            return Node(
36                min(root->val, left.minNode),
37                max(root->val, right.maxNode),
38                currSum
39            );
40        }
41
42        // If not BST
43        // return invalid range so parent cannot form BST
44        return Node(INT_MIN, INT_MAX, 0);
45    }
46
47    int maxSumBST(TreeNode* root) {
48        solve(root);   
49        return ans;
50    }
51};