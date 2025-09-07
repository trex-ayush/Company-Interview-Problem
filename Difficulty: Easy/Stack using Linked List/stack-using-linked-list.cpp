class MyStack {
  private:
    StackNode *head;
    
  public:
    MyStack() { 
        head = NULL;
    }
    
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (!head) return -1;
        
        int value = head->data;
        head = head->next;
        
        return value;
    }
};