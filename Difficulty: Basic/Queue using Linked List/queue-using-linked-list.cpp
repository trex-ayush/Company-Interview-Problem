/*
class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
class MyQueue {
public:
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
*/

void MyQueue::push(int x) {
    QueueNode* newNode = new QueueNode(x);
    if (rear == NULL) {
        front =  newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int MyQueue::pop() {
    if (front == NULL) return -1;
    
    int value = front->data;
    
    front = front->next;
    if (front == NULL) rear = NULL;
    
    return value;
}
