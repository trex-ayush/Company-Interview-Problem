/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    string traversal(Node *head){
        Node* temp = head;
        
        string ans = "";
        while(temp){
            ans += temp->data;
            temp = temp->next;
        }
        
        return ans;
    }
    bool check(string &ans){
        int s = 0;
        int e = ans.length() - 1;
        
        while(s <= e){
            if(ans[s++] != ans[e--]) return false;
        }
        
        return true;
    }
    bool isPalindrome(Node *head) {
        // Your code here
        string ans = traversal(head);
        
        return check(ans);
    }
};

