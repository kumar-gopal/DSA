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
    node *rear;
    node *front;

public:
    Queue(/* args */);
    ~Queue();
    void push(int x);
    void view();
    void pop();
    int first();
    int last();
    bool isempty();
    int size();
};
int Queue::size()
{
    node *temp = front;
    int cnt = 0;
    while (temp)
    {
        cnt++;
       temp=temp->next;
    }
    return cnt;
}
bool Queue::isempty()
{
    return (rear == nullptr && front == nullptr);
}

int Queue::first()
{
    return (front->data);
}
int Queue::last()
{
    return (rear->data);
}
Queue::Queue()
{
    rear = nullptr;
    front = nullptr;
}
void Queue::push(int x)
{
    node *n = new node;
    n->data = x;
    n->next = nullptr;
    if (rear == 0 && front == 0)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}
void Queue::view()
{
    node *temp = front;
    if (temp == nullptr)
        cout << "empty Queue\n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Queue::pop()
{
    if (front == nullptr)
    {
        cout << "underflow\n";
        return;
    }
    node *del = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    delete del;
}
Queue::~Queue()
{
    while (front)
        pop();
}
int main()
{
    Queue q;
    q.push(1);
    q.view();
    q.push(2);
    cout<<"size->"<<q.size()<<endl;
    q.view();
    q.push(3);
    q.view();
    q.push(7);
    cout<<"size->"<<q.size()<<endl;
    q.pop();
    q.pop();
    cout << "first -> " << q.first() << " \n";
    cout << "last -> " << q.last() << " \n";
    q.view();
}
