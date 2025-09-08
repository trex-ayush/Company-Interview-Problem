/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        if(!left) return right;
        if(!right) return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left && right){
            if(left->data < right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        
        Node* mid = getMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* res = merge(left, right);
        
        return res;
    }
};