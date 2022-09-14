// circular queue implemented using circular Linked List
#include <iostream>
using namespace std;
class Queue
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *front, *rear;

public:
    Queue();
    ~Queue();
    void push(int x);
    void pop();
    void view();
    int first();
    int last();
};
int Queue::first()
{
    return (front->data);
}
int Queue::last()
{
    return (rear->data);
}
void Queue::pop()
{
    if (rear == nullptr)
    {
        cout << "Queue is empty";
        return;
    }
    node *temp = front;
    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    delete temp;
}
void Queue::push(int x)
{
    node *n = new node;
    n->data = x;
    if (rear == nullptr)
    {
        n->next = n;
        rear = n;
        front = n;
    }
    else
    {
        n->next = rear->next;
        rear->next = n;
        rear = n;
    }
}
void Queue::view()
{
    if (rear == nullptr)
    {
        cout << "empty Queue\n";
        return;
    }
    node *temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}
Queue::Queue(/* args */)
{
    front = rear = nullptr;
}

Queue::~Queue()
{
    node *t = front;
    while (t != rear)
    {
        t = t->next;
        pop();
    }
    if (t == rear)
        pop();
}
int main()
{
    Queue q;
    q.push(1);
    q.view();
    q.push(2);
    q.view();
    q.push(3);
    q.view();
    q.push(5);
    cout << q.first() << endl;
    cout << q.last() << endl;
    q.~Queue();
    q.view();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(6);
    cout << q.first() << endl;
    cout << q.last() << endl;
    q.view();
}