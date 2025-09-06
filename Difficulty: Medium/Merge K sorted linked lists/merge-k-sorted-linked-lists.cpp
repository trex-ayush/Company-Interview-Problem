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
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> pq(
            [](Node* a, Node* b) {
                return a->data > b->data; // only for heaps
            }
        );
        
        for (Node* list : arr) {
            if (list) pq.push(list);
        }
        
        Node* dummy = new Node(0);
        Node* current = dummy;
        
        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            
            if (node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};