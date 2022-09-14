#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int capacity;
    int rear, front;
    int *ptr;

public:
    CircularQueue();
    ~CircularQueue();
    void createQueue(int size);
    void push(int x);
    void pop();
    int isempty();
    int isfull();
    void view();
};
int CircularQueue::isempty()
{
    return (rear == -1 && front == -1);
}
int CircularQueue::isfull()
{
    return (((rear + 1) % capacity) == front);
}
void CircularQueue::pop()
{
    if (front == -1)
    {
        cout << "empty Queue\n";
        return;
    }
    else if (rear == front)
    {
        rear = front = -1;
        return;
    }
    front = (front + 1) % capacity;
}
void CircularQueue::push(int x)
{
    if (((rear + 1) % capacity) == front)
    {
        cout << "Queue is full.\n";
        return;
    }
    else if (rear == -1 && front == -1)
    {
        rear = front = 0;
        ptr[rear] = x;
    }
    else
    {
        rear = (rear + 1) % capacity;
        ptr[rear] = x;
    }
}
void CircularQueue::view()
{
    int temp = front;
    if (temp == -1)
    {
        cout << "Queue is empty \n";
        return;
    }
    while (temp != rear)
    {
        cout << ptr[temp] << " ";
        temp = (temp + 1) % capacity;
    }
    cout << ptr[temp] << "\n";
}
void CircularQueue::createQueue(int size)
{
    capacity = size;
    ptr = new int[capacity];
}
CircularQueue::CircularQueue(/* args */)
{
    capacity = 0;
    rear = front = -1;
    ptr = nullptr;
}
CircularQueue::~CircularQueue()
{

    while (front != rear)
    {
        pop();
    }
    pop();
}
int main()
{
    CircularQueue q;
    q.createQueue(5);
    q.push(1);
    q.view();
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.~CircularQueue();
    q.view();
}